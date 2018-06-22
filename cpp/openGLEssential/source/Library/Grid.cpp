#include "pch.h"

using namespace glm;
using namespace std;

namespace Library
{
	RTTI_DEFINITIONS(Grid)

	const GLuint Grid::DefaultSize = 16;
	const GLuint Grid::DefaultScale = 16;
	const vec4 Grid::DefaultColor = vec4(0.961f, 0.871f, 0.702f, 1.0f);

	Grid::Grid(Game& game, Camera& camera, GLuint size, GLuint scale, const vec4& color) :
		DrawableGameComponent(game, camera), mVertexArrayObject(0), mVertexBuffer(0),
		mPosition(Vector3Helper::Zero), mSize(size), mScale(scale), mColor(color),
		mVertexCount(0)
	{
	}
	
	Grid::~Grid()
	{
		glDeleteBuffers(1, &mVertexBuffer);
		glDeleteVertexArrays(1, &mVertexArrayObject);
	}

	const vec3& Grid::Position() const
	{
		return mPosition;
	}

	const vec4& Grid::Color() const
	{
		return mColor;
	}

	const GLuint Grid::Size() const
	{
		return mSize;
	}

	const GLuint Grid::Scale() const
	{
		return mScale;
	}

	void Grid::SetPosition(const vec3& position)
	{
		mPosition = position;
		mWorldMatrix = translate(mat4(), mPosition);
	}

	void Grid::SetPosition(float x, float y, float z)
	{
		mPosition = vec3(x, y, z);
		mWorldMatrix = translate(mat4(), mPosition);
	}

	void Grid::SetColor(const vec4& color)
	{
		mColor = color;
		InitializeGrid();
	}

	void Grid::SetSize(GLuint size)
	{
		mSize = size;
		InitializeGrid();
	}

	void Grid::SetScale(GLuint scale)
	{
		mScale = scale;
		InitializeGrid();
	}

	void Grid::Initialize()
	{
		SetCurrentDirectory(Utility::ExecutableDirectory().c_str());

		// Build the shader program
		vector<ShaderDefinition> shaders;
		shaders.push_back(ShaderDefinition(GL_VERTEX_SHADER, L"Content\\Effects\\BasicEffect.vert"));
		shaders.push_back(ShaderDefinition(GL_FRAGMENT_SHADER, L"Content\\Effects\\BasicEffect.frag"));
		mShaderProgram.BuildProgram(shaders);

		InitializeGrid();

		// Create the vertex array object
		glGenVertexArrays(1, &mVertexArrayObject);		
		mShaderProgram.Initialize(mVertexArrayObject);
		glBindVertexArray(0);
	}

	void Grid::Draw(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
	
		mShaderProgram.Use();

		mat4 wvp = mCamera->ViewProjectionMatrix() * mWorldMatrix;
		mShaderProgram.WorldViewProjection() << wvp;

		glDrawArrays(GL_LINES, 0, mVertexCount);
		glBindVertexArray(0);
	}

	void Grid::InitializeGrid()
	{
		mVertexCount = (mSize + 1) * 4;
		unique_ptr<VertexPositionColor[]> vertexData = make_unique<VertexPositionColor[]>(mVertexCount);
		VertexPositionColor* vertices = vertexData.get();

		float adjustedScale = mScale * 0.1f;
		float maxPosition = mSize * adjustedScale / 2;

        for (unsigned int i = 0, j = 0; i < mSize + 1; i++, j = 4 * i)
        {
            float position = maxPosition - (i * adjustedScale);

            // Vertical line
			vertices[j] = VertexPositionColor(vec4(position, 0.0f, maxPosition, 1.0f), mColor);
            vertices[j + 1] = VertexPositionColor(vec4(position, 0.0f, -maxPosition, 1.0f), mColor);

            // Horizontal line
            vertices[j + 2] = VertexPositionColor(vec4(maxPosition, 0.0f, position, 1.0f), mColor);
            vertices[j + 3] = VertexPositionColor(vec4(-maxPosition, 0.0f, position, 1.0f), mColor);
        }

		glDeleteBuffers(1, &mVertexBuffer);

		mShaderProgram.CreateVertexBuffer(vertices, mVertexCount, mVertexBuffer);
	}
}