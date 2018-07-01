package renderEngine;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.nio.FloatBuffer;
import java.nio.IntBuffer;
import java.util.ArrayList;
import java.util.List;

import org.lwjgl.BufferUtils;
import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL15;
import org.lwjgl.opengl.GL20;
import org.lwjgl.opengl.GL30;
import org.newdawn.slick.opengl.Texture;
import org.newdawn.slick.opengl.TextureLoader;

import models.RawModel;
 

// loading 3D model into memory, store position data in a VAO
public class Loader {

	// keep track of the memory 
	private List<Integer> vaos = new ArrayList<Integer>();
	private List<Integer> vbos = new ArrayList<Integer>();
	private List<Integer> textures = new ArrayList<Integer>();
	
	// delete buffers
	public void cleanUp() {
		for(int vao:vaos) {
			GL30.glDeleteVertexArrays(vao);
		}
		for(int vbo:vbos) {
			GL15.glDeleteBuffers(vbo);
		}
		
		for(int texture : textures) {
			GL11.glDeleteTextures(texture);
		}
	}
	
	public RawModel loadToVAO (float [] positions, float[] textureCoords, int[] indices) {
		// create an empty VAO
		int vaoID = createVAO();
		
		// bind indices buffer
		bindIndicesBuffer(indices);
		
		// store the data into one attribute of the vao
		storeDataInAttributeList(0, 3 , positions);     // position coordinate is 3d
		storeDataInAttributeList(1, 2, textureCoords);  // texture is 2d 
		
		unbindVAO();
		return new RawModel(vaoID, indices.length);
	}
	
	
	public int loadTexture(String fileName) {
		
		Texture texture = null;
		
		try {
			texture = TextureLoader.getTexture("PNG", new FileInputStream("res/" + fileName + ".png"));
			
		} catch (FileNotFoundException e) {
			 
			e.printStackTrace();
		} catch (IOException e) {
			 
			e.printStackTrace();
		}
		
		
		int textureID = texture.getTextureID();
		textures.add(textureID);
		return textureID;
	}
	
	
	// create a VAO
	private int createVAO() {	
		
		// create vao
		int vaoID = GL30.glGenVertexArrays();
		vaos.add(vaoID);
		//activate
		GL30.glBindVertexArray(vaoID);
		return vaoID;
	}
	
	// store the data into an attribute of the VAO
	private void storeDataInAttributeList(int attributeNumber,int coordinateSize /*2d, 3d*/,  float[] data) {
		
		// create a vbo
		int vboID = GL15.glGenBuffers();  
		vbos.add(vboID);
		// bind vbo
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, vboID);
		
		// convert float array to float buffer
		FloatBuffer buffer = storeDataInFloatBuffer(data);
		//float buffer => vbo 
		GL15.glBufferData(GL15.GL_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW);
		//put vbo to an attribte of vao : attrib number ; length of each vertex, type of data; is normalized ; distance between vertices ;offset
		GL20.glVertexAttribPointer(attributeNumber, coordinateSize,  GL11.GL_FLOAT, false, 0, 0);
		
		// unbind vbo
		GL15.glBindBuffer(GL15.GL_ARRAY_BUFFER, 0); // unbind vbo
		
	}
	
	// unbinds VAO after finishing using it
	private void unbindVAO() {
		
		GL30.glBindVertexArray(0);
	}
	
	private void bindIndicesBuffer(int[] indices) {
		
		// create indices buffer
		int vboID = GL15.glGenBuffers();
		// track it in list 
		vbos.add(vboID);
		//bind
		GL15.glBindBuffer(GL15.GL_ELEMENT_ARRAY_BUFFER, vboID);
		
		// convert indices array to indices buffer
		IntBuffer buffer = storeDataInIntBuffer(indices);
		
		// store it into vbo
		GL15.glBufferData(GL15.GL_ELEMENT_ARRAY_BUFFER, buffer, GL15.GL_STATIC_DRAW);
		
		
		
	}
	
	// indices => indices buffer
	private IntBuffer storeDataInIntBuffer(int[] data) {
		//create int buffer
		IntBuffer buffer = BufferUtils.createIntBuffer(data.length);
		//put data into the buffer
		buffer.put(data);
		//move to start, get ready to be read
		buffer.flip();
		
		return buffer;	
		
	}
	
	
	
	// float array to float buffer
	private FloatBuffer storeDataInFloatBuffer(float[] data) {
		FloatBuffer buffer = BufferUtils.createFloatBuffer(data.length);
		buffer.put(data);
		// prepare buffer to be read from
		buffer.flip();
		return buffer;
	}
}
