#include "pch.h"

using namespace glm;
using namespace std;
using namespace Library;

namespace Rendering
{
	RTTI_DEFINITIONS(TexturedModelDemo)

	TexturedModelDemo::TexturedModelDemo(Game& game, Camera& camera) :
		DrawableGameComponent(game, camera), mKeyboardHandler(nullptr), mVertexArrayObject(0), mVertexBuffer(0),
		mIndexBuffer(0), mWorldViewProjectionLocation(-1), mIndexCount(0), mColorTexture(0),
		mAltTexture(0), mActiveTexture(0)
	{
	}

	TexturedModelDemo::~TexturedModelDemo()
	{
		glDeleteTextures(1, &mAltTexture);
		glDeleteTextures(1, &mColorTexture);
		glDeleteBuffers(1, &mIndexBuffer);
		glDeleteBuffers(1, &mVertexBuffer);
		glDeleteVertexArrays(1, &mVertexArrayObject);

		mGame->RemoveKeyboardHandler(mKeyboardHandler);
	}

	void TexturedModelDemo::Initialize()
	{
		SetCurrentDirectory(Utility::ExecutableDirectory().c_str());

		// Build the shader program
		vector<ShaderDefinition> shaders;
		shaders.push_back(ShaderDefinition(GL_VERTEX_SHADER, L"Content\\Effects\\TexturedModelDemo.vert"));
		shaders.push_back(ShaderDefinition(GL_FRAGMENT_SHADER, L"Content\\Effects\\TexturedModelDemo.frag"));
		mShaderProgram.BuildProgram(shaders);
		
		// Load the model
		Model model("Content\\Models\\Sphere.obj", true);

		// Create the vertex and index buffers
		Mesh* mesh = model.Meshes().at(0);
		CreateVertexBuffer(*mesh, mVertexBuffer);
		mesh->CreateIndexBuffer(mIndexBuffer);
		mIndexCount = mesh->Indices().size();
		
		mWorldViewProjectionLocation = glGetUniformLocation(mShaderProgram.Program(), "WorldViewProjection");
		if (mWorldViewProjectionLocation == -1)
		{
			throw GameException("glGetUniformLocation() did not find uniform location.");
		}

		// Load the texture
		mColorTexture = SOIL_load_OGL_texture("Content\\Textures\\EarthComposite.jpg", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB );
		if (mColorTexture == 0)
		{
			throw GameException("SOIL_load_OGL_texture() failed.");
		}

		mAltTexture = SOIL_load_OGL_texture("Content\\Textures\\Checkerboard.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS | SOIL_FLAG_NTSC_SAFE_RGB);
		if (mAltTexture == 0)
		{
			throw GameException("SOIL_load_OGL_texture() failed.");
		}

		mActiveTexture = mColorTexture;

		// Create vertex array objects (VAOs)
		glGenVertexArrays(1, &mVertexArrayObject);
		glBindVertexArray(mVertexArrayObject);

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::Position), 4, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTexture), (void*)offsetof(VertexPositionTexture, Position));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::Position));

		glVertexAttribPointer(static_cast<GLuint>(VertexAttribute::TextureCoordinate), 2, GL_FLOAT, GL_FALSE, sizeof(VertexPositionTexture), (void*)offsetof(VertexPositionTexture, TextureCoordinates));
		glEnableVertexAttribArray(static_cast<GLuint>(VertexAttribute::TextureCoordinate));

		glBindVertexArray(0);

		using namespace std::placeholders;
		mKeyboardHandler = bind(&TexturedModelDemo::OnKey, this, _1, _2, _3, _4);
		mGame->AddKeyboardHandler(mKeyboardHandler);
	}

	void TexturedModelDemo::Draw(const GameTime& gameTime)
	{
		UNREFERENCED_PARAMETER(gameTime);

		glBindVertexArray(mVertexArrayObject);
		glBindBuffer(GL_ARRAY_BUFFER, mVertexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mIndexBuffer);		
		glBindTexture(GL_TEXTURE_2D, mActiveTexture);

		glUseProgram(mShaderProgram.Program());

		mat4 wvp = mCamera->ViewProjectionMatrix() * mWorldMatrix;
		glUniformMatrix4fv(mWorldViewProjectionLocation, 1, GL_FALSE, &wvp[0][0]);

		glEnable(GL_CULL_FACE);
		glFrontFace(GL_CCW);

		glDrawElements(GL_TRIANGLES, mIndexCount, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}

	void TexturedModelDemo::CreateVertexBuffer(const Mesh& mesh, GLuint& vertexBuffer)
	{
		const vector<vec3>& sourceVertices = mesh.Vertices();

		vector<VertexPositionTexture> vertices;
		vertices.reserve(sourceVertices.size());

		vector<vec3>* textureCoordinates = mesh.TextureCoordinates().at(0);
		assert(textureCoordinates->size() == sourceVertices.size());

		for (size_t i = 0; i < sourceVertices.size(); i++)
		{
			const vec3& position = sourceVertices.at(i);
			const vec2& uv = static_cast<vec2>(textureCoordinates->at(i));
			vertices.push_back(VertexPositionTexture(vec4(position.x, position.y, position.z, 1.0f), uv));
		}

		glGenBuffers(1, &vertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(VertexPositionTexture) * vertices.size(), &vertices[0], GL_STATIC_DRAW);
	}

	void TexturedModelDemo::OnKey(int key, int scancode, int action, int mods)
	{
		UNREFERENCED_PARAMETER(scancode);
		UNREFERENCED_PARAMETER(mods);

		if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
		{
			if (mActiveTexture == mColorTexture)
			{
				mActiveTexture = mAltTexture;
			}
			else
			{
				mActiveTexture = mColorTexture;
			}
		}
	}
}