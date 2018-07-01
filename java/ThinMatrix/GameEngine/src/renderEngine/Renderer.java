package renderEngine;

import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL13;
import org.lwjgl.opengl.GL20;
import org.lwjgl.opengl.GL30;

import models.RawModel;
import models.TexturedModel;

// render the model
public class Renderer {

	// every frame clear
	public void prepare() {

		GL11.glClear(GL11.GL_COLOR_BUFFER_BIT);
		GL11.glClearColor(1, 0, 0, 1);
	}
	
	
	public void render(TexturedModel texturedModel) {
		RawModel model = texturedModel.getRawModel();
		
		
		// bind vao
		GL30.glBindVertexArray(model.getVaoID());
		
		//activate the attribute list in which our data is stored
		GL20.glEnableVertexAttribArray(0);
		GL20.glEnableVertexAttribArray(1);
		
		
		GL13.glActiveTexture(GL13.GL_TEXTURE0);
		GL11.glBindTexture(GL11.GL_TEXTURE_2D, texturedModel.getTexture().getID());
		// render a vbo : type, first, how many vertices
		// GL11.glDrawArrays(GL11.GL_TRIANGLES, 0, model.getVertexCount());  // for vbo
		
		// render a ibo
		GL11.glDrawElements(GL11.GL_TRIANGLES, model.getVertexCount(), GL11.GL_UNSIGNED_INT, 0);
		
		// disable the attribute list
		GL20.glDisableVertexAttribArray(0);
		GL20.glDisableVertexAttribArray(1);
		
		// unbind vao
		GL30.glBindVertexArray(0);
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
