package renderEngine;

import org.lwjgl.opengl.GL11;
import org.lwjgl.opengl.GL20;
import org.lwjgl.opengl.GL30;

// render the model
public class Renderer {

	// every frame clear
	public void prepare() {

		GL11.glClear(GL11.GL_COLOR_BUFFER_BIT);
		GL11.glClearColor(1, 0, 0, 1);
	}
	
	
	public void render(RawModel model) {
		
		// bind vao
		GL30.glBindVertexArray(model.getVaoID());
		
		//activate the attribute list in which our data is stored
		GL20.glEnableVertexAttribArray(0);
		// render a vbo : type, first, how many vertices
		// GL11.glDrawArrays(GL11.GL_TRIANGLES, 0, model.getVertexCount());  // for vbo
		
		// render a ibo
		GL11.glDrawElements(GL11.GL_TRIANGLES, model.getVertexCount(), GL11.GL_UNSIGNED_INT, 0);
		
		// disable the attribute list
		GL20.glDisableVertexAttribArray(0);
		
		// unbind vao
		GL30.glBindVertexArray(0);
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
