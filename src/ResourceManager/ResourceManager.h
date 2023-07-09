#pragma once

#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <unordered_map>
#include <filesystem>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "../Utils/FileUtil.h"

template <typename Resource>
class ResourceManager {

    private:

        const std::filesystem::path s_folder;

        const std::string s_extension;

        std::unordered_map<std::string, Resource> s_resources;

        std::filesystem::path getFullFilePath(const std::string& name) {
            return s_folder / (name + s_extension);
        };


    public:

        ResourceManager(const std::string& folder, const std::string& extension)
            : s_folder(getPath() / folder)
            , s_extension('.' + extension) 
        {};


        const Resource& get(const std::string& name) {
            if(!exists(name)) {
                    add(name);
                }
                return s_resources.at(name);
        };


        bool exists(const std::string& name) const {
            return s_resources.find(name) != s_resources.end();
        };
            
        
        void add(const std::string& name) {
            Resource r;
            
            if(!r.loadFromFile(getFullFilePath(name).string())) {
                Resource fail;
                fail.loadFromFile((s_folder / ("_fail_" + s_extension)).string());
                s_resources.insert(std::make_pair(name, fail));
            }
            else {
                s_resources.insert(std::make_pair(name, r));
            }
        };
};

#endif