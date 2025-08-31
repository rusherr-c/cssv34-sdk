#include "eiface.h"
#include "cdll_int.h"
#include "convar.h"

IVEngineClient* cl_engine = nullptr;
IVEngineServer* sv_engine = nullptr;

int CCommand::ArgC() const
{
    if (sv_engine)
        return sv_engine->Cmd_Argc();
    else if (cl_engine)
        return cl_engine->Cmd_Argc();
    return 0;
}

const char* CCommand::Arg(int nIndex) const
{
    if (sv_engine)
        return sv_engine->Cmd_Argv(nIndex);
    else if (cl_engine)
        return cl_engine->Cmd_Argv(nIndex);
    return "";
}

const char* CCommand::ArgV(int nIndex) const {
    return Arg(nIndex);
}

const char* CCommand::operator[](int nIndex) const {
    return Arg(nIndex);
}

const char* CCommand::ArgS() const
{
    if (sv_engine)
        return sv_engine->Cmd_Args(); // server can do it
    else if (cl_engine)
    {
        // client can't do it
        static char buf[1024];
        buf[0] = '\0';
        int argc = cl_engine->Cmd_Argc();
        for (int i = 1; i < argc; i++)
        {
            strcat(buf, cl_engine->Cmd_Argv(i));
            if (i < argc - 1)
                strcat(buf, " ");
        }
        return buf;
    }
    return "";
}

const char* CCommand::GetCommandString() const {
    return ArgS();
}

