#include "pch.h"

using namespace glm;
using namespace std;
using namespace Library;

namespace Rendering
{
	RTTI_DEFINITIONS(CubeDemo)

	const GLfloat CubeDemo::RotationRate = pi<float>();

	CubeDemo::CubeDemo(Game& game, Camera& camera) :
		DrawableGameComponent(game, camera), mVertexArrayObject(0), mVertexBuffer(0),
		mIndexBuffer(0), mWorldViewProjectionLocation(-1), mIndexCount(0)
	{
	}

	CubeDemo::~CubeDemo()
	{
		glDeleteBuffers(1, &mIndexBuffer);
		glDeleteBuffers(1, &mVertexBuffer);
		glDeleteVertexArrays(1, &mVertexArrayObject);
	}

	void CubeDemo::Initialize()
	{
		SetCurrentDirectory(Utility::ExecutableDirectory().c_str());

		// Build the shader program
		vector<ShaderDefinition> shaders;
		shaders.push_back(ShaderDefinition(GL_VERTEX_SHADER, L"Content\\Effects\\CubeDemo.vert"));
		shaders.push_back(ShaderDefinition(GL_FRAGMENT_SHADER, L"Content\\Effects\\CubeDemo.frag"));
		mShaderProgram.BuildProgram(shaders);
		
		// Create the vertex buffer object
		VertexPositionColor vertices[] =
		{
			VertexPositionColor(vec4(-1.0f, +1.0f, -1.0f, 1.0f), ColorHelper::Green),
			VertexPositionColor(vec4(+1.0f, +1.0f, -1.0f, 1.0f), ColorHelper::Yellow),
			VertexPositionColor(vec4(+1.0f, +1.0f, +1.0f, 1.0f), ColorHelper::White),
			VertexPositionColor(vec4(-1.0f, +1.0f, +1.0f, 1.0f), ColorHelper::BlueGreen),

			VertexPositionColor(vec4(-1.0f, -1.0f, +1.0f, 1.0f), ColorHelper::Blue),
			VertexPositionColor(vec4(+1.0f, -1.0f, +1.0f, 1.0f), ColorHelper::Purple),
			VertexPositionColor(vec4(+1.0f, -1.0f, -1.0f, 1.0f), ColorHelper::Red),
			VertexPositionColor(vec4(-1.0f, -1.0f, -1.0f, 1.0f), ColorHelper::Black)
		};

		glGenBuffers(1, &mVertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		uint32_t indices[] =
		{
			0, 2, 1,
			0, 3, 2,

			4, 6, 5,
			4, 7, 6,

			3, 5, 2,
			3, 4, 5,

			2, 6, 1,
			2, 5, 6,

			1, 6, 7,
			1, 7, 0,

			0, 4, 3,
			0, 7, 4
		};

		mIndexCount = ARRAYSIZE(indices);

		glGenBuffers(1, &mIndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * mIndexCount, indices, GL_STATIC_DRAW);

		// Create the vertex array object
		glGenVertexArrays(1, &mVertexArrayObject);
		glBindVertexArray(mVertexArrayObject);

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Position), 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), (void*)offsetof(VertexPositionColor, Position));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Position));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Color), 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionColor), (void*)offsetof(VertexPositionColor, Color));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Color));

		glBindVertexArray(0);

		mWorldViewProjectionLocation = glGetUniformLocation(mShaderProgram.Program(), "WorldViewProjection");
		if (mWorldViewProjectionLocation == -1)
		{
			throw GameException("glGetUniformLocation() did not find uniform location.");
		}
	}

	void CubeDemo::Update(const GameTime& gameTime)
	{
		static float angle = 0.0f;

		angle += gameTime.ElapsedGameTimeSeconds().count() * RotationRate;

		mWorldMatrix = rotate(mat4(), angle, Vector3Helper::Up);
	}

	void CubeDemo::Draw(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);

		glUseProgram(mShaderProgram.Program());

		mat4 wvp = mCamera->ViewProjectionMatrix() * mWorldMatrix;
		glUniformMatrix4fv(mWorldViewProjectionLocation, 1, GL_FALSE, &wvp[0][0]);

		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CCW);

		glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
}