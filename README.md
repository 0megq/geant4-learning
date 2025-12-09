# Geant4 Learning :D

This repo is the project I am creating while going along with these [geant4 tutorials by Physics Matters](https://www.youtube.com/playlist?list=PLLybgCU6QCGUYAOwtyI4U8cRL6ig0p3c7).

At the time of writing, a basic Geant4 project has been setup with a particle gun that shoots 1GeV positrons.

# Running the project

If you have installed Geant4 using the [tutorial by Physics Matters](https://www.youtube.com/watch?v=4DTumUo3IKw&list=PLLybgCU6QCGUYAOwtyI4U8cRL6ig0p3c7&index=2), everything should work just fine. If you've installed it another way then it might work.

Do the following:

1. Create build folder within the project directory
2. Run geant4make.sh, located inside the folder `<Geant4 Install Directory>/share/Geant4/geant4make`. If you followed the Geant4 tutorial by Physics Matters you can also just run `geant4make` in the terminal.
3. Run the following commands from `<Project Directory>/build`:

```bash
cmake ..	# run cmake config
make		# compile the project
./sim		# run the executable
```

4. Enjoy!

# Include paths and extensions for VS Code

I recommend installing the C/C++ Extension Pack and also adding your [geant4 install to the include path](https://youtu.be/xpHeGwHqyzQ?si=JRR0rIW_IMifpHPE&t=533).

