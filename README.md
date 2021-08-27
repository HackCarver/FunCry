
# FunCry
A randomizer for FarCry 2004 v1.4 (CryEngine 1)

# Building
You need the BINK SDK (not uploaded here because of licensing issues). Alternatively, open ProjectDefines.h and un-comment the lines that say "#define NOT_USE_BINK_SDK" to remove the BINK dependency. However you lose the ability to play some cutscenes as well as the demo loop

You'll need Visual Studio 2003 or the alternative Code::Blocks setup. The instructions for Code::Blocks that have been handed out a lot do not work on new versions of Windows 10. Also they are a bit convoluted and only work if you compile in the release profile. So really VS 2003 sounds like the way to go. There's probably a project included for both IDEs

# Discord
https://discord.gg/nVdPPkf<br>

# Issues
A: There's a range of issues with this mod, mainly regarding the HUD<br>
B: Inconsistencies. Code quality varies a lot, and so does the styling<br>
C: Maybe the \*license as well? This thing is built on top of the CryENGINE 1.4 MOD SDK, which has it's own (included) license. Sure, the core of the mod is safe as it is entirely original and only uses the API. Cool, but then some is also embedded in the SDK (typically marked tho)<br>

\*The other way would be to cut out all the external stuff, and distribute ONLY the original stuff. Basically have some laundry list of softwares to hunt down and install. Then the changes to the SDK files could be automatically added via some little text merging tool. Same result, less messy with mixing all this third party crap into it on the GitHub side of it. More messy for the developer tho

# Features
A real-time audio modification hook<br>
A load-time character modification hook<br>
