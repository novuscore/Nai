#include <pch/Build.h>
#include <iostream>
#include <chrono>

#include "Compiler/Lexer/Lexer.h"
#include "Compiler/Parser/Parser.h"
#include "Compiler/Bytecode/BytecodeGenerator.h"
#include "Compiler/Bytecode/BytecodeVM.h"

#include "Utils/CLIParser.h"

#ifdef _WIN32
#include <Windows.h>
#include <WinBase.h>
#endif

#ifdef TRACY_ENABLE
void* operator new(std::size_t count)
{
    auto ptr = malloc(count);
    TracyAlloc(ptr, count);
    return ptr;
}
void operator delete(void* ptr) noexcept
{
    TracyFree(ptr);
    free(ptr);
}
#endif

int Compile(const std::string& fileName)
{
    ZoneScopedNC("Compile", tracy::Color::Red);

    BytecodeVM vm(1);
    vm.RunScript(fileName);

    return 0;
}

int main(int argc, char* argv[])
{
    ZoneScoped;

#ifdef _WIN32
    SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_HIGHEST);
#endif

    CLIParser cliParser; // Default implicit parameters are "executable" which gets the path to the current executable, and "filename" which gets the file we're acting on

    cliParser.AddParameter("unittest", "Runs a unittest on the file")
             .AddParameter("testoutput", "The output location for unittests, [REQUIRED] if doing unittest");

    CLIValues values = cliParser.ParseArguments(argc, argv);

    if (!values["filename"_h].WasDefined())
    {
        cliParser.PrintHelp();
        return -1;
    }

    std::string filename = values["filename"_h].As<std::string>();
    return Compile(filename);
}