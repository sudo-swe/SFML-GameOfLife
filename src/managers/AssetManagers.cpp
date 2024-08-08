#include "managers/AssetManager.hpp"

namespace GameOfLife {
    void AssetManager::LoadFont(std::string name, std::string filePath){
        sf::Font font;
        if(font.loadFromFile(filePath)) this->fonts[name] = font;
    }

    sf::Font &AssetManager::GetFont(std::string name){
        return this->fonts.at(name);
    }

    void AssetManager::LoadTexture(std::string name, std::string filePath){
        sf::Texture texture;
        if(texture.loadFromFile(filePath)) this->textures[name] = texture;
    }

    sf::Texture &AssetManager::GetTexture(std::string name){
        return this->textures.at(name);
    }
}
