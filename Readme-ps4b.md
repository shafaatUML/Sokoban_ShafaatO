# PS4a: Sokoban

## Contact
Name: Shafaat Osmani
Section: 201
Time to Complete: 14+ Hours


## Description
Explain what the project does.
## The project displays the starter layout for a sokoban game by getting the layout from a text file, then using the text file as a key to display the starter layout. 
## The project now successfully simulates a sokoban game. 

### Features
Describe what your major decisions were and why you did things that way.
## My program scans in the text file into a vector of strings. I implemented it in this certain way due to strings being able to be treated like arrays. The simplicity of being able to access each character within the string by using index notiation such as [][] made it easy to set the proper texture for my sprite and display to the window.
## I had to create a new vector to save the original state of the txt file in order to re-draw the target tiles after the player moves off of them. Movement is also prevented after the player wins the game and I accomplished this by putting the sfml key inputs into a while loop (while the game is not won, allow movement). I also used the original txt file to rewrite to the vector map when reset key is pressed, and then the draw function will draw everything over from scratch. I do not implement any sort of moveable sprite at all, as my original implementation does not allow for that. I am simply drawing the player sprite at a different location every time by changing up the vector that the draw function uses. I found this to be simpler than using a sprite as the overriden draw function does not allow for modification as it is const, so altering a sprite member variable would not be possible. I also had to account for every case in my move function. For example, if there is a wall behind the crate in the direction the player is trying to push it, I had to account to make sure the move function did not allow for any changes to be made to the vector. 

### Memory
Describe how you decided to store the level data including whether you used smart pointers.
## I did not use smart pointers. Instead I used a vector of strings. To display the block to the screen I used a sprite and set the texture equivalent to its txt file character. For example, a # character would set the texture to wall, and a wall would be displayed in the correct location.
## As mentioned above, I also included a new vector to save the original txt. 

### Lambdas
Describe what <algorithm> functions you used and what lambda expressions you wrote.
## The algorithm function I used was for_each.  The lambda expression was implemented with the purpose of printing out the txt file back from the string.

### Issues
What did you have trouble with?  What did you learn?  What doesn't work?  Be honest.  You might be penalized if you claim something works and it doesn't.
## I am unsure if I am doing the scaling properly. My program works for all types of txt inputs, but I am not sure if the window needs to be resized if the input becomes too big (ex: 600 x 600). I had the most trouble with figuring out a way to do my draw function. At first, I attempted to make a vector of textures or sprites and use both my vector of strings and this second vector to work in cooperation with one another to get the right texture to the right character. It turned out that the easier way for me was to just do a simple set of if-else statements using the original vector of strings. 
## The largest issue I had to deal with was trying to get the crate to re-draw. I mentioned how I was able to solve this in the first section. Another issue was trying to optimize the program. Originally I had the program search the original vector every single time through a loop until it found the player, and then manipulate the tiles around it. This overheated my computer and was very slow. I had to switch to using x and y values for the player index and use those to manipulate the proper tiles.

### Extra Credit
Anything special you did.  This is required to earn bonus points.


## Acknowledgements
List all sources of help including the instructor or TAs, classmates, and web pages.
If you used images or other resources than the ones provided, list them here.

## https://www.geeksforgeeks.org/for_each-loop-c/
## https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.
## https://www.sfml-dev.org/tutorials/2.5/graphics-sprite.php
## font is sourced from: https://fonts.google.com/