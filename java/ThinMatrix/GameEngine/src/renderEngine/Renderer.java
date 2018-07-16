package renderEngine;

import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL13;
import org.lwjgl.opengl.GL20;
import org.lwjgl.opengl.GL30;
import org.lwjgl.util.vector.Matrix4f;

import entities.Entity;
import models.RawModel;
import models.TexturedModel;
import shaders.StaticShader;
import toolbox.Maths;

// render the model
public class Renderer {

	// every frame clear
	public void prepare() {

		GL11.glClear(GL11.GL_COLOR_BUFFER_BIT);
		GL11.glClearColor(1, 0, 0, 1);
	}
	
	
	public void render(Entity entity, StaticShader shader) {
		
		TexturedModel model = entity.getModel();
		
		RawModel rawModel = model.getRawModel();
		
		
		// bind vao
		GL30.glBindVertexArray(rawModel.getVaoID());
		
		//activate the attribute list in which our data is stored
		GL20.glEnableVertexAttribArray(0);
		GL20.glEnableVertexAttribArray(1);
		
		Matrix4f transformationMatrix = Maths.createTransformationMatrix(entity.getPosition(), 
				entity.getRotX(), entity.getRotY(), entity.getRotZ(), entity.getScale());
		
		shader.loadTransformationMatrix(transformationMatrix);
		//
		
		GL13.glActiveTexture(GL13.GL_TEXTURE0);
		GL11.glBindTexture(GL11.GL_TEXTURE_2D, model.getTexture().getID());
		// render a vbo : type, first, how many vertices
		// GL11.glDrawArrays(GL11.GL_TRIANGLES, 0, model.getVertexCount());  // for vbo
		
		// render a ibo
		GL11.glDrawElements(GL11.GL_TRIANGLES, rawModel.getVertexCount(), GL11.GL_UNSIGNED_INT, 0);
		
		// disable the attribute list
		GL20.glDisableVertexAttribArray(0);
		GL20.glDisableVertexAttribArray(1);
		
		// unbind vao
		GL30.glBindVertexArray(0);
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
