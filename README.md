# TF2 Post-round Friendly Fire

Inspired by the functionality in [Pre-Fortress 2](https://store.steampowered.com/app/3555120/PreFortress_2/), the purpose of this repository is for the intention of adding post-round friendly fire as a cvar.

There has been extensive work done to the code in order to allow this to function. 

The cvar name is `tf_round_end_friendlyfire` and has 3 separate modes.
- 0: Off.
- 1: On, but no player collisions.
- 2: On, and player collisions are enabled.

The reason for player collisions is to enable certain functionality that server operators may want, such as the ability to charge into a teammate as the Demoman and impact them, or to land on a teammate's with the Mantreads. These will not work when the cvar is set to 1. However, setting it to 2 could cause issues such as players being stuck inside one another when a round ends. Basically? Pick your poison. 

Great effort has been made to make it so that every weapon should act as it does in the normal game when fighting an enemy player or building, with some caveats. 
When Friendly Fire mode is enabled and the round is over:

- Sentries will not auto-target teammates after the round is over. The Engineer can, however, make use of his wrangler to shoot and blow up his teammates!
- Telefragging teammates is possible regardless of which FF mode is enabled.
- All Soldier banners have been edited so that they are only active for the player that has deployed it.
- Backstabbing a teammate with the Your Eternal Reward will show your teammates that you stabbed a teammate with it.
- Mediguns are unaffected and will work as normal. Be careful who you decide to heal, or they may turn on you next! 

There may be other edge cases that have not been covered here. 

For anyone that is adding this to their own SDK game, I'd also recommend changing `mp_bonusroundtime` in `teamplayroundbased_gamerules.cpp` from it's base cap of 15s to something like 30-60s, configurable by the server operator. This is fun functionality, give people more time to murder their teammates! 

My only request is that if you use this in your own project, please credit me. If you find issues with the code, find something I missed, or have a better way to refactor some areas, please open a PR!

Thanks,

SaintSoftware

___
*Original SDK Readme:*
___

# Source SDK 2013

Source code for Source SDK 2013.

Contains the game code for Half-Life 2, HL2: DM and TF2.

**Now including Team Fortress 2! ✨**

## Build instructions

Clone the repository using the following command:

`git clone https://github.com/ValveSoftware/source-sdk-2013`

### Windows

Requirements:
 - Source SDK 2013 Multiplayer installed via Steam
 - Visual Studio 2022 with the following workload and components:
   - Desktop development with C++:
     - MSVC v143 - VS 2022 C++ x64/x86 build tools (Latest)
     - Windows 11 SDK (10.0.22621.0) or Windows 10 SDK (10.0.19041.1)
 - Python 3.13 or later

Inside the cloned directory, navigate to `src`, run:
```bat
createallprojects.bat
```
This will generate the Visual Studio project `everything.sln` which will be used to build your mod.

Then, on the menu bar, go to `Build > Build Solution`, and wait for everything to build.

You can then select the `Client (Mod Name)` project you wish to run, right click and select `Set as Startup Project` and hit the big green `> Local Windows Debugger` button on the tool bar in order to launch your mod.

The default launch options should be already filled in for the `Release` configuration.

### Linux

Requirements:
 - Source SDK 2013 Multiplayer installed via Steam
 - podman

Inside the cloned directory, navigate to `src`, run:
```bash
./buildallprojects
```

This will build all the projects related to the SDK and your mods automatically against the Steam Runtime.

You can then, in the root of the cloned directory, you can navigate to `game` and run your mod by launching the build launcher for your mod project, eg:
```bash
./mod_tf
```

*Mods that are distributed on Steam MUST be built against the Steam Runtime, which the above steps will automatically do for you.*

## Distributing your Mod

There is guidance on distributing your mod both on and off Steam available at the following link:

https://partner.steamgames.com/doc/sdk/uploading/distributing_source_engine

## Additional Resources

- [Valve Developer Wiki](https://developer.valvesoftware.com/wiki/Source_SDK_2013)

## License

The SDK is licensed to users on a non-commercial basis under the [SOURCE 1 SDK LICENSE](LICENSE), which is contained in the [LICENSE](LICENSE) file in the root of the repository.

For more information, see [Distributing your Mod](#markdown-header-distributing-your-mod).
