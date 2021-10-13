#include <iostream>
#include <SDL.h>
#include <string>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "button.h"
#include "commandButton.h"
#include "ClickCommand.h"
#include "FireCommand.h"
#include "MixCommand.h"
#include "macroCommand.h"
#include "BalanceCommand.h"
#include "material.h"
#include <vector>

class Game
{
public:
    Game();
    ~Game() = default;

    void init(std::string t_windowName, int t_x, int t_y, int t_width, int t_height, Uint32 t_flags);

    void handleInputs();
    void update();
    void render();

    void cleanup();

    bool isRunning();
private:
    void showMats();
    void handleActiveButton(float x, float y);

    void printTotals();

    void updateTotals();

    std::vector<Button*> m_buttons;
    std::vector<Material*> m_mats;
    Button* m_activeButton;
    TTF_Font* m_gameFont;
    bool m_isRunning;
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    MacroCommand m_commands;

    SDL_Texture* m_totalsText;
    SDL_Rect m_totalsRect;
};