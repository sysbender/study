package engineTester;

import org.lwjgl.opengl.Display;

import models.RawModel;
import models.TexturedModel;
import renderEngine.DisplayManager;
import renderEngine.Loader;
import renderEngine.Renderer;
import shaders.StaticShader;
import textures.ModelTexture;
 

public class MainGameLoop {

	public static void main(String[] args) {
		
		
		DisplayManager.createDisplay();
		
		
		// create loader and renderer
		Loader loader = new Loader();
		Renderer renderer = new Renderer();	
		
		
		// shader
		StaticShader shader = new StaticShader();
		
		
		
		//OpenGL expects vertices to be defined counter clockwise by default
		// position coordinates
		float[] vertices = {
			//left bottom triangle	
				-0.5f, 0.5f, 0f, //v0
				-0.5f, -0.5f, 0f, //v1
				0.5f, -0.5f, 0f, //v2 
				0.5f, 0.5f, 0f  //v3				
		};
		// texture coordinates
		float[] textureCoords= {
				0,0, //v0
				0,1, //v1
				1,1, //v2
				1,0  //v3
		};
		
		
		int[] indices = {
				0,1,3,
				3,1,2
		};
		

		
		RawModel model = loader.loadToVAO(vertices,textureCoords , indices);
		ModelTexture texture = new ModelTexture(loader.loadTexture("image"));
		TexturedModel texturedModel = new TexturedModel(model, texture);
		
		
		while(!Display.isCloseRequested()) {
			
			
			renderer.prepare();
			// game logic
			shader.start();
			renderer.render(texturedModel);
			shader.stop();
			//render
			
			DisplayManager.updateDisplay();
		}
		

		shader.cleanUp();
		loader.cleanUp();
		DisplayManager.closeDisplay();
		

	}

}
