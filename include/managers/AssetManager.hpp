#pragma once

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <map>
#include <string>


namespace GameOfLife {
    class AssetManager{
        public:
            AssetManager(){}
            ~AssetManager(){}

            void LoadFont(std::string name, std::string filePath);
            sf::Font &GetFont(std::string name);
            void LoadTexture(std::string name, std::string filePath);
            sf::Texture &GetTexture(std::string name);

        private:
            std::map<std::string, sf::Font> fonts;
            std::map<std::string, sf::Texture> textures;
    };
}
