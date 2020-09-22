#include "RenderController.h"

RenderController::RenderController(King::Engine* engine, Board* board, InfoPanel* info)
	: mEngine(engine)
	, mBoard(board)
	, mInfoPanel(info)
{
}

void RenderController::Update()
{
	int posY = mEngine->GetTextureHeight(King::Engine::TEXTURE_BG_TOP);
	mEngine->Render(King::Engine::TEXTURE_BG_BOTTOM, 0.0f, float(posY));

	mBoard->Update();
	mInfoPanel->Update();

	mEngine->Render(King::Engine::TEXTURE_BG_TOP, 0.0f, 0.0f);
}