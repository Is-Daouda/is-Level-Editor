#include "LevelEditor.h"

LevelEditor::LevelEditor(sf::RenderWindow &window, sf::View &view, sf::RenderTexture &surface, GameSystemExtended &gameSysExt):
    GameDisplay(window, view, surface, gameSysExt, sf::Color::White),
    AUTO_SAVE_MINUTE(2),
    m_cursor(this),
    m_gameTime(AUTO_SAVE_MINUTE, 0, 0), // save the level every AUTO_SAVE_MINUTE minutes
    m_closeLevelEditor(false),
    m_showItemMenuList(false),
    m_levelIsChanged(false),
    m_levelWidth(0),
    m_levelHeight(0),
    m_validationKeyPressedTime(0)
{
    m_levelPath = m_gameSysExt.m_filePath;
    m_texBlockPath    = "";
    m_texPlayerPath   = "";
    m_texGameplayPath = "";
    m_texBonusPath    = "";
    m_texEnemyPath    = "";
    m_texTilesPath    = "";
    for (auto &x : m_itemMenuListScale) x = 1.f;

    // redefine view parameter
    m_viewX = (m_viewW / 2.f);
    m_viewY = (m_viewH / 2.f);

    srand(time(NULL));
}


LevelEditor::~LevelEditor()
{
}
