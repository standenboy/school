import pygame


class entity:
    def __init__(self, x, y, img, radius, color):
        self.rotation = 0

        self.radius = radius
        self.pos = pygame.Vector2(x, y)
        self.hitbox = pygame.Rect(x, y, radius*2, radius*2)
        self.color = color
        self.hitbox.x = x
        self.hitbox.y = y

        self.sprite = pygame.image.load(img)
        self.sprite = pygame.transform.scale(self.sprite,
                                             (radius * 2, radius * 2))

        self.hitbox.x = self.pos.x - self.radius
        self.hitbox.y = self.pos.y - self.radius

    def move(self):
        keys = pygame.key.get_pressed()
        if keys[pygame.K_w]:
            self.pos.y -= 300 * dt
        if keys[pygame.K_s]:
            self.pos.y += 300 * dt
        if keys[pygame.K_a]:
            self.pos.x -= 300 * dt
        if keys[pygame.K_d]:
            self.pos.x += 300 * dt

        while self.pos.x > 1280:
            self.pos.x = self.pos.x - 1
        while self.pos.x < 0:
            self.pos.x = self.pos.x + 1
        while self.pos.y > 720:
            self.pos.y = self.pos.y - 1
        while self.pos.y < 0:
            self.pos.y = self.pos.y + 1
        self.hitbox.x = self.pos.x - self.radius
        self.hitbox.y = self.pos.y - self.radius

    def update(self, things, rot):
        pass
    def draw(self, debug):
        screen.blit(self.sprite, self.pos)
        if debug == 1:
            pygame.draw.rect(screen, self.color, self.hitbox)

    def __collide(self, things):
        for i in things:
            if self.hitbox.colliderect(i.hitbox):
                return i


pygame.init()
screen = pygame.display.set_mode((1280, 720))
clock = pygame.time.Clock()
running = True
dt = 0

bg = pygame.image.load("./bg.png")
bg = pygame.transform.scale(bg, (1280, 720))

player = entity(screen.get_width() / 2, screen.get_height() / 2,
                "./player.png", 40, "red")

enemys = []
for i in range(3):
    enemys.append(entity(100, 100, "./player.png", 40, "blue"))

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    screen.blit(bg, (0, 0))

    player.update(enemys, 1)

    player.move()

    player.draw(1)
    for i in enemys:
        i.draw(0)

    pygame.display.flip()

    dt = clock.tick(30) / 1000

pygame.quit()
