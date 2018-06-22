#pragma once

#include "RTTI.h"
#include "Variable.h"
#include <string>
#include <vector>
#include <map>
#include <cstdint>
#include <GL/glcorearb.h>

namespace Library
{
	class Model;
	class Mesh;

	typedef std::pair<GLenum, std::wstring> ShaderDefinition;

	class ShaderProgram : public RTTI
	{
		RTTI_DECLARATIONS(ShaderProgram, RTTI)

	public:
		ShaderProgram();
		ShaderProgram(const ShaderProgram&) = delete;
		ShaderProgram& operator=(const ShaderProgram&) = delete;
		ShaderProgram(ShaderProgram&&) = delete;
		ShaderProgram& operator=(ShaderProgram&&) = delete;
		virtual ~ShaderProgram();
		
		static GLuint CompileShaderFromFile(GLenum shaderType, const std::wstring& filename);

		GLuint Program() const;	
		const std::vector<Variable*>& Variables() const;
		const std::map<std::string, Variable*>& VariablesByName() const;

		void BuildProgram(const std::vector<ShaderDefinition>& shaderDefinitions);

		virtual void Initialize(GLuint vertexArrayObject);
		virtual void Use() const;
		virtual void CreateVertexBuffer(const Model& model, std::vector<GLuint>& vertexBuffers) const;
		virtual void CreateVertexBuffer(const Mesh& mesh, GLuint& vertexBuffer) const;
		virtual std::uint32_t VertexSize() const;

	protected:
		std::map<std::string, Variable*> mVariablesByName;		
		std::vector<Variable*> mVariables;
		GLuint mProgram;		
	};

	#define SHADER_VARIABLE_DECLARATION(VariableName)		\
		public:												\
		Library::Variable& VariableName() const;			\
	private:												\
		Library::Variable* m ## VariableName;

	#define SHADER_VARIABLE_DEFINITION(ShaderProgram, VariableName)		\
		Library::Variable& ShaderProgram::VariableName() const			\
		{																\
			return *m ## VariableName;									\
		}

	#define SHADER_VARIABLE_INITIALIZATION(VariableName) m ## VariableName(nullptr)

	#define SHADER_VARIABLE_INSTANTIATE(VariableName)															\
		m ## VariableName = new Variable(*this, #VariableName);													\
		mVariables.push_back(m ## VariableName);																\
		mVariablesByName.insert(std::pair<std::string, Variable*>(m ## VariableName->Name(), m ## VariableName));
}
