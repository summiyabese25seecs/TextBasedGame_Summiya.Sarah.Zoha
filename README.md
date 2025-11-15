# Roles
**Summiya Aurangzeb:** Made the initial program logic and wrote the code for Escape Mystery Game.  
**Zoha Ahsan:** Managed readme and the documentation.  
**Sarah Shahid:** Made the program logic and designed a detailed flow chart.  

---

# Program Logic
The Escape Mystery Game takes place in a haunted house with 3 levels; Attic, library and kitchen. In each level, the player has to choose a key. The key decides whether the game will be continued, the player will lose a life out of his total 8 lives or the game will be over. If the player chooses the right key and the game is continued then he has to guess a secret number with limited tries.  

- Attic (1 – 10) in 3 tries  
- Library (1 – 15) in 4 tries  
- Kitchen (1 – 15) in 4 tries  

If he guesses the right number, he will either clear the level or escape the haunted house. If he fails, he will lose a life. The player wins if he successfully escapes the room and if he is out of lives, he will lose and the game will end.  

---

# Functions Used
**start():** Gives the introduction of game and tells the rule. It marks the start of the game.  
**keys1():** It controls the first key choice of user in the attic.  
**password_room1():** It runs the attic number guessing game (1 – 10) and leads to next level if successful.  
**library():** It marks the start of level 2 and asks user to choose second key.  
**keys2():** It manages the key selection and leads to number guessing part if successful.  
**password_room2():** It runs the library number guessing game (1 – 15) and leads to next level if successful.  
**kitchen():** It marks the start of level 3 and asks user to choose the last key.  
**keys3():** It manages the key selection and leads to the final number guessing part if successful.  
**password_room3():** It runs the kitchen number guessing game (1 – 20) and decides if the player won or lose.
