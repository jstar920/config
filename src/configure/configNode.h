#pragma once
#pragma once

#include <string>
#include <functional>
#include <map>
#include <memory>

namespace configure
{
    class ConfigNode
    {
    public:
        ConfigNode(const std::string& name);
        virtual bool isCommandNode() { return false; }
        virtual bool isConfigureNode() { return false; }
        virtual bool isPathNode() { return true; }

        std::string getName() const { return name; }
        std::string getHelpMessage() const { return helpMessage; }
    protected:
        std::string name;
        std::string helpMessage;
        std::map<std::string, std::unique_ptr<ConfigNode>> subNode;
    };
}