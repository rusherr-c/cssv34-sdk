#include <unordered_map>

//--------------------------------------------------------
// CAUTION: This header file is now unused, since i
//  moved code of this header to tier1\convar.h.
// DO NOT USE THIS, otherwise you will get a ton of errors
// -------------------------------------------------------

typedef void (*FnCommandCallback_t)(const CCommand& args);
typedef ::ConCommand ValveConCommand;

// ConCommand: basic CCommand implementation
class ConCommand
{
public:
	ConCommand(const char* pName, FnCommandCallback_t callback, const char* pHelpString = 0, int flags = 0);
private:
	ValveConCommand* m_Command;
	static std::unordered_map<std::string, FnCommandCallback_t> m_Callbacks;
};

// basic CCommand implementation
class CCommand
{
public:
	int ArgC() const;
	const char* ArgV(int index) const;
	const char* ArgS() const;
	const char* Arg(int index) const;
	const char* GetCommandString() const;

	// operator
	const char* operator[](int index) const;
};

std::unordered_map<std::string, FnCommandCallback_t> ConCommand::m_Callbacks;