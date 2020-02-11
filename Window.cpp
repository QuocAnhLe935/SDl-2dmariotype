#include "Window.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream> 

Window::Window(int width_, int height_){
	screenSurface = nullptr;
	window = nullptr;
	width = width_;
	height = height_;
}

bool Window::OnCreate(){
	window = SDL_CreateWindow("My First Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
	if (window == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}

	screenSurface = SDL_GetWindowSurface(window);
	if (screenSurface == nullptr) {
		std::cout << "SDL_Error: " << SDL_GetError() << std::endl;
		return false;
	}
	return true;
}

void Window::OnDestroy(){
	/// Kill the surface first
	if (screenSurface) {
		SDL_FreeSurface(screenSurface);
	}

	/// Now kill the window
	if (window){
		SDL_DestroyWindow(window);
	}
	


}

Window::~Window(){}

SDL_Window* Window::GetSDL_Window() {
	return window;
}