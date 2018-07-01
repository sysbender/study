package shaders;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL20;

public abstract class ShaderProgram {
	
	private int programID;
	private int vertexShaderID;
	private int fragmentShaderID;
	
	
	public ShaderProgram(String vertexFile, String fragmentFile) {
		vertexShaderID = loadShader(vertexFile, GL20.GL_VERTEX_SHADER);
		fragmentShaderID = loadShader(fragmentFile, GL20.GL_FRAGMENT_SHADER);
		
		programID = GL20.glCreateProgram();
		GL20.glAttachShader(programID, vertexShaderID);
		GL20.glAttachShader(programID, fragmentShaderID);		
		
		bindAttributes();
		
		GL20.glLinkProgram(programID);
		GL20.glValidateProgram(programID);

		
	}
	
	// start , use program id
	public void start() {
		GL20.glUseProgram(programID);
	}
	
	// stop , use program id =0
	public void stop() {
		GL20.glUseProgram(0);
	}
	
	
	public void cleanUp() {
		
		stop();
		//detach shader
		GL20.glDetachShader(programID, vertexShaderID);
		GL20.glDetachShader(programID, fragmentShaderID);
		
		// delete shader
		GL20.glDeleteShader(vertexShaderID);
		GL20.glDeleteShader(fragmentShaderID);
		
		// delete program
		GL20.glDeleteProgram(programID);
		
	}
	protected abstract void bindAttributes();
	
	protected void bindAttribute(int attributeID, String variableName) {
		
		GL20.glBindAttribLocation(programID, attributeID, variableName);
		
	}

	private static int loadShader(String fileName, int shaderType) {
		//read file to string
		StringBuilder shaderSource = new StringBuilder();
		
		try {
			
			BufferedReader reader = new BufferedReader(new FileReader(fileName));
			String line;
			while((line = reader.readLine( ) )!=null) {
				shaderSource.append(line).append("\n");
			}
			reader.close();
			
		}catch(IOException e) {
			System.err.println("Could not read file :" + fileName);
			e.printStackTrace();
			System.exit(-1);
		}
		
		// compile shader
		int shaderID =GL20.glCreateShader(shaderType);
		GL20.glShaderSource(shaderID, shaderSource);
		GL20.glCompileShader(shaderID);
		if(GL20.glGetShaderi(shaderID, GL20.GL_COMPILE_STATUS)== GL11.GL_FALSE) {
			System.out.println(GL20.glGetShaderInfoLog(shaderID, 500));
			System.err.println("Error : Could not compile shader");
			System.exit(-1);
		}
		
		return shaderID;
		
	}

}
