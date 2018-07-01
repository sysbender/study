package engineTester;

import org.lwjgl.opengl.Display;

import renderEngine.DisplayManager;
import renderEngine.Loader;
import renderEngine.RawModel;
import renderEngine.Renderer;
import shaders.StaticShader;
 

public class MainGameLoop {

	public static void main(String[] args) {
		
		
		DisplayManager.createDisplay();
		
		
		// create loader and renderer
		Loader loader = new Loader();
		Renderer renderer = new Renderer();	
		
		
		// shader
		StaticShader shader = new StaticShader();
		
		
		
		//OpenGL expects vertices to be defined counter clockwise by default
		float[] vertices = {
			//left bottom triangle	
				-0.5f, 0.5f, 0f, //v0
				-0.5f, -0.5f, 0f, //v1
				0.5f, -0.5f, 0f, //v2 
				0.5f, 0.5f, 0f  //v3				
		};
		int[] indices = {
				0,1,3,
				3,1,2
		};
		
		RawModel model = loader.loadToVAO(vertices, indices);
		
		
		while(!Display.isCloseRequested()) {
			
			
			renderer.prepare();
			// game logic
			shader.start();
			renderer.render(model);
			shader.stop();
			//render
			
			DisplayManager.updateDisplay();
		}
		

		shader.cleanUp();
		loader.cleanUp();
		DisplayManager.closeDisplay();
		

	}

}
