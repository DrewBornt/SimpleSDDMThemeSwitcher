# A Simple SDDM Theme Switcher

#### md5sum:
4f9fa2c23169c70c2211c8d8564a9adc

### How to use: 
./simplethemeswitcher <"theme-name">

./simplethemeswitcher list (to be implemented)


## Compiling

If you'd like to just compile the code yourself, ensure gcc is installed on your system.
Then navigate into the directory with 'main.c'
```
gcc main.c -o simplethemeswitcher
```

#### Written by: Drew Bornt 

After installing Arch on my personal laptop and trying to navigate myself around how to use it, I wanted to be able to easily change my SDDM theme from the terminal without opening a file or other program.

Sure, if you're using a more fleshed out distro, you'll already have some GUI tool to set a theme.

But if I know the name of the theme, why can't I just change it from a terminal without having to go and edit a cofig file? That's exactly what this program will do for you.