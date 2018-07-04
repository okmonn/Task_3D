#include "Game.h"
#include "DxLib.h"

// �G���g���[�|�C���g
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	Game& game = Game::Get();
	game.Init();
	game.Accept();
	game.End();
	return 0;
}