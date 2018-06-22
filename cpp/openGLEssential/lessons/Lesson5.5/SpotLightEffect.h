#pragma once

#include "ShaderProgram.h"
#include "VertexDeclarations.h"

namespace Rendering
{
	class SpotLightEffect : public Library::ShaderProgram
    {
		RTTI_DECLARATIONS(SpotLightEffect, Library::ShaderProgram)

        SHADER_VARIABLE_DECLARATION(WorldViewProjection)
		SHADER_VARIABLE_DECLARATION(World)
		SHADER_VARIABLE_DECLARATION(AmbientColor)
		SHADER_VARIABLE_DECLARATION(LightColor)
		SHADER_VARIABLE_DECLARATION(LightPosition)
		SHADER_VARIABLE_DECLARATION(LightRadius)
		SHADER_VARIABLE_DECLARATION(LightLookAt)
		SHADER_VARIABLE_DECLARATION(CameraPosition)
		SHADER_VARIABLE_DECLARATION(SpecularColor)
		SHADER_VARIABLE_DECLARATION(SpecularPower)
		SHADER_VARIABLE_DECLARATION(SpotLightInnerAngle)
		SHADER_VARIABLE_DECLARATION(SpotLightOuterAngle)

    public:
        SpotLightEffect();

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