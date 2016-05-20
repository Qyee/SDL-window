// sdl1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SDL.h"
#include <iostream>

#pragma comment(lib, "./SDL2.0.4/lib/x86/SDL2.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	SDL_Window	*pWindow = nullptr;
	SDL_Renderer*pRenderer = nullptr;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		std::cout << "SDL initialize fail: " << SDL_GetError() << std::endl;
		return -1;
	}
	pWindow = SDL_CreateWindow("SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		640, 480,
		SDL_WINDOW_SHOWN);
	if (NULL == pWindow)
	{
		std::cout << "Create window fail : " << SDL_GetError() << std::endl;
	}
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

	SDL_SetRenderDrawColor(pRenderer, 0, 0xaa, 0xaa, 0xaa);
	SDL_RenderClear(pRenderer);
	SDL_RenderPresent(pRenderer);

	//消息循环
	SDL_Event sldEvent;
	bool bQuit = false;
	while (!bQuit)
	{
		while (SDL_PollEvent(&sldEvent))
		{
			switch (sldEvent.type)
			{
			case SDL_QUIT:
				bQuit = true;
				break;
			}
		}
	}
	return 0;
}