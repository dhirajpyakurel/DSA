import pygame
import random
import math
from pygame import mixer
from collections import deque
import time

# Initialize the pygame
pygame.init()

# Create the screen
screen = pygame.display.set_mode((800, 600))

#Global variable to loop the game until it is quited
global start_game
start_game = True

#Implementation of QUEUE
# creating a deque to store the score numbers
#score_queue = deque(maxlen=50)
#q = queue.Queue()

queue = []


while start_game == True:
    q=0

    start_game = False

    # Background
    background = pygame.image.load("2799006.jpg")

    # Background Sound
    #mixer.music.load('background.wav')
    #mixer.music.play(-1)

    # Game Title and Logos:
    pygame.display.set_caption("Space Fighters")
    icon = pygame.image.load('project.png')
    pygame.display.set_icon(icon)

    # Player
    playerImg = pygame.image.load("ufo-2.png")
    playerX = 370
    playerY = 480
    playerX_change = 0

    # Enemy
    enemyImg = []
    enemyX = []
    enemyY = []
    enemyX_change = []
    enemyY_change = []
    no_of_enemies = 8

    for i in range(no_of_enemies):
        enemyImg.append(pygame.image.load("monster.png"))
        enemyX.append(random.randint(0, 735))
        enemyY.append(random.randint(50, 150))
        enemyX_change.append(1)
        enemyY_change.append(0)

    # Bullet
    # Ready -> we can't see the bullet
    bulletImg = pygame.image.load("bullet copy.png")
    bulletX = 0
    bulletY = 480
    bulletX_change = 0
    bulletY_change = 10
    bullet_state = "ready"

    # Score Value
    score_value = 0
    font = pygame.font.Font('ArialRound.ttf', 30)
    textX = 10
    textY = 10

    # Game-Over Text
    game_over = pygame.font.Font('ArialRound.ttf', 70)

    #Score list font
    score_list = pygame.font.Font('ArialRound.ttf', 35)

    #Score list font
    highscore = pygame.font.Font('ArialRound.ttf', 45)

    # Displaying player
    def player(x, y):
        screen.blit(playerImg, (x, y))


    # Displaying enemy
    def enemy(x, y, i):
        screen.blit(enemyImg[i], (x, y))


    # Displaying bullet
    def bullet(x, y):
        global bullet_state
        bullet_state = "fire"
        screen.blit(bulletImg, (x + 16, y + 10))


    # Check Collision
    def is_collision(enemyX, enemyY, bulletX, bulletY):
        dist = math.sqrt((math.pow(enemyX - bulletX, 2)) + (math.pow(enemyY - bulletY, 2)))
        if dist < 27:
            return True
        else:
            return False


    # Displaying the score
    def show_score(x, y):
        score = font.render("Score : " + str(score_value), True, (237, 210, 163))
        screen.blit(score, (x, y))

    def sort(queue):
        n = len(queue)
        for i in range(n):
            for j in range(0, n-i-1):
                if queue[j] < queue[j+1]:
                    queue[j], queue[j+1] = queue[j+1], queue[j]
        return queue

    # Game_over screen
    def game_over_text(x, y):
        over = game_over.render("Game Over", True, (189, 141, 253))
        screen.blit(over, (x, y))
        pygame.time.delay(200)
        high_s = highscore.render("High Score : ", True, (204, 102, 51))
        screen.blit(high_s, (250, 250))
        t = 280
        p = 280
        for z in range(len(queue)):
            p += 40
            score_l = score_list.render(f"{z+1})  {queue[z]}", True, (137, 209, 133))
            screen.blit(score_l, (t, p))
            #pygame.display.update()

    # Game loop until QUIT
    running = True
    while running:

        # Filling blackscreen
        screen.fill((0, 0, 0))

        # Applying background image
        screen.blit(background, (0, 0))

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                start_game = False

            # If keystroke is pressed , check whether is right or left:
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_LEFT:
                    playerX_change = -1.5

                if event.key == pygame.K_RIGHT:
                    playerX_change = +1.5

                if event.key == pygame.K_SPACE:
                    if bullet_state == "ready":
                        bullet_sound = mixer.Sound('laser.wav')
                        bullet_sound.play()
                        bulletX = playerX
                        bullet(bulletX, bulletY)

                if event.key == pygame.K_RETURN:
                    start_game = True
                    running = False

                # if event.key == pygame.K_q:



                if event.key == pygame.K_1:
                    playerImg = pygame.image.load("ufo-2.png")
                    bulletImg = pygame.image.load("bullet copy.png")

                if event.key == pygame.K_2:
                    playerImg = pygame.image.load("spaceship-2.png")
                    bulletImg = pygame.image.load("bullet.png")

                if event.key == pygame.K_3:
                    playerImg = pygame.image.load("spaceship.png")
                    bulletImg = pygame.image.load("bullets.png")

            if event.type == pygame.KEYUP:
                if event.key == pygame.K_LEFT or event.key == pygame.K_RIGHT:
                    playerX_change = 0


        # Checking for boundaries of spaceship
        playerX += playerX_change
        if playerX < 0:
            playerX = 0
        if playerX > 736:
            playerX = 736

        # Movements of enemy
        for i in range(no_of_enemies):
            if enemyY[i] > 450:

                for j in range(no_of_enemies):
                    enemyY[j] = 2000

                while q==0:
                    queue.append(score_value)
                    q+=1
                sort(queue)
                game_over_text(200,150)
                #Adding each value in queue

                break

            enemyX[i] += enemyX_change[i]
            xspeed_of_enemies = 1
            if enemyX[i] <= 0:
                if score_value <= 25:
                    enemyX_change[i] = +xspeed_of_enemies
                    enemyY[i] += 30
                elif score_value > 25 and score_value <= 50:
                    enemyX_change[i] = +(xspeed_of_enemies + .3)
                    enemyY[i] += 30
                elif score_value > 50 and score_value <= 100:
                    enemyX_change[i] = +(xspeed_of_enemies + .5)
                    enemyY[i] += 30
                elif score_value > 100 and score_value <= 200:
                    enemyX_change[i] = +(xspeed_of_enemies + .8)
                    enemyY[i] += 30
                elif score_value > 200 and score_value <= 300:
                    enemyX_change[i] = +(xspeed_of_enemies + 1.1)
                    enemyY[i] += 30
                else:
                    enemyX_change[i] = +(xspeed_of_enemies + 1.5)
                    enemyY[i] += 30

            elif enemyX[i] >= 736:
                if score_value <= 25:
                    enemyX_change[i] = -xspeed_of_enemies
                    enemyY[i] += 30
                elif score_value > 25 and score_value <= 50:
                    enemyX_change[i] = -(xspeed_of_enemies + .3)
                    enemyY[i] += 30
                elif score_value > 50 and score_value <= 100:
                    enemyX_change[i] = -(xspeed_of_enemies + .3)
                    enemyY[i] += 30
                elif score_value > 100 and score_value <= 200:
                    enemyX_change[i] = -(xspeed_of_enemies + .3)
                    enemyY[i] += 30
                elif score_value > 200 and score_value <= 300:
                    enemyX_change[i] = -(xspeed_of_enemies + .3)
                    enemyY[i] += 30
                else:
                    enemyX_change[i] = -(xspeed_of_enemies + 1.5)
                    enemyY[i] += 30

            # Collision
            collision = is_collision(enemyX[i], enemyY[i], bulletX, bulletY)
            if collision:
                explosion_sound = mixer.Sound('explosion.wav')
                explosion_sound.play()
                bulletY = 480
                bullet_state = "ready"
                score_value += 1
                enemyX[i] = random.randint(100, 700)
                enemyY[i] = random.randint(50, 150)

            enemy(enemyX[i], enemyY[i], i)

        # Bullet Movement
        if bulletY <= 0:
            bulletY = 480
            bullet_state = "ready"
        if bullet_state == "fire":
            bullet(bulletX, bulletY)
            bulletY -= bulletY_change

        show_score(textX, textY)
        player(playerX, playerY)
        pygame.display.update()
    #Adding each value in queue
    # queue.append(score_value)
