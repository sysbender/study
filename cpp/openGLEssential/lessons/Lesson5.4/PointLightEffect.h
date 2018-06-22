#pragma once

#include "ShaderProgram.h"
#include "VertexDeclarations.h"

namespace Rendering
{
	class PointLightEffect final : public Library::ShaderProgram
    {
		RTTI_DECLARATIONS(PointLightEffect, Library::ShaderProgram)

        SHADER_VARIABLE_DECLARATION(WorldViewProjection)
		SHADER_VARIABLE_DECLARATION(World)
		SHADER_VARIABLE_DECLARATION(AmbientColor)
		SHADER_VARIABLE_DECLARATION(LightColor)
		SHADER_VARIABLE_DECLARATION(LightPosition)
		SHADER_VARIABLE_DECLARATION(LightRadius)
		SHADER_VARIABLE_DECLARATION(CameraPosition)
		SHADER_VARIABLE_DECLARATION(SpecularColor)
		SHADER_VARIABLE_DECLARATION(SpecularPower)

    public:
        PointLightEffect();

		virtual void Initialize(GLuint vertexArrayObject) override;
		virtual void CreateVertexBuffer(const Library::Mesh& mesh, GLuint& vertexBuffer) const override;
		void CreateVertexBuffer(Library::VertexPositionTextureNormal* vertices, std::uint32_t vertexCount, GLuint& vertexBuffer) const;
		virtual std::uint32_t VertexSize() const override;

	private:
		enum class VertexAttribute
		{
			Position = 0,
			TextureCoordinate = 1,
			Normal = 2
		};
    };
}