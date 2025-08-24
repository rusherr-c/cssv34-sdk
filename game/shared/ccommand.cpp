#include <cbase.h>

static std::unordered_map<std::string, FnCommandCallback_t> m_Callbacks;
ConCommand *m_Command;

ConCommand::ConCommand(const char* pName, FnCommandCallback_t callback, const char* pHelpString, int flags)
{
    m_Callbacks[pName] = callback;

    auto wrapper = [](void)
        {
            CCommand cmd;

            const char* name = cmd[0];
            auto it = m_Callbacks.find(name);

            if (it != m_Callbacks.end() && it->second)
                it->second(cmd);
        };

    m_Command = new ConCommand(pName, wrapper, pHelpString, flags);
}


int CCommand::ArgC() const
{
    return engine->Cmd_Argc();
}

const char* CCommand::ArgV(int index) const
{
    return engine->Cmd_Argv(index);
}

const char* CCommand::Arg(int index) const
{
    return engine->Cmd_Argv(index);
}

const char* CCommand::operator[](int index) const
{
    return engine->Cmd_Argv(index);
}

const char* CCommand::ArgS() const
{
    return engine->Cmd_Args();
}

const char* CCommand::GetCommandString() const
{
    return engine->Cmd_Args();
}

