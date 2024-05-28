/*
** EPITECH PROJECT, 2024
** GAME-RPG
** File description:
** init
*/

#include "my_rpg.h"

void push_to_back_dialogue(dialogue_t **head, dialogue_t *new_dialogue)
{
    dialogue_t *current;

    if (*head == NULL) {
        *head = new_dialogue;
    } else {
        current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_dialogue;
    }
    new_dialogue->next = NULL;
}

void set_default_value(dialogue_t *new)
{
    new->activ = false;
    new->txt_is_hover = false;
    new->txt_id = 0;
    new->letter_id = 0;
    new->tmp = strdup("\0");
    new->text_obj = sfText_create();
    new->font = sfFont_createFromFile(FONT_PATH);
    new->animation_sprite = sfSprite_create();
    new->animation_rect = (sfIntRect){0, 288/2, 576 / 4, 288 / 2};
    new->animation_pos = (sfVector2f){0, 0};
    new->clock = sfClock_create();
    new->clock_letter = sfClock_create();
    sfText_setFont(new->text_obj, new->font);
    sfText_setCharacterSize(new->text_obj, 50);
    sfText_setColor(new->text_obj, sfWhite);
    new->next = NULL;
}

/*
Pour faire apparaitre un dialogue :
    Appeler cette fonction que 1 fois : get_dialogue(rpg_t, ID);
*/
static void init_dialogue_1(rpg_t *rpg)
{
    dialogue_t *new = malloc(sizeof(dialogue_t));
    sfVector2f scale = {2.0, 2.0};

    set_default_value(new);
    new->animation_texture =
        sfTexture_createFromFile("assets/pnj/archertheresa_faces.png", NULL);
    // Modifier le nombre de textes et les textes ici
    new->nb_text = 7;
    new->text = malloc(sizeof(char *) * 3);
    new->text[0] = strdup("Salut, aventurier, tu as vu mon mot ?\0");
    new->text[1] = strdup("Moi c'est Ryia, l'archère la plus talentueuse du royaume, \nou du moins la dernière…\0");
    new->text[2] = strdup("Mais attends, tu ne serais pas Roy, l'aventurier dont sa \nmajesté m'a parlé?\0");
    new->text[3] = strdup("Je me suis engagé à t'aider à te préparer, donc je vais \nt'indiquer où tu pourrais trouver de l'équipement.\0");
    new->text[4] = strdup("Je sais qu'il y a une épée bien meilleure que la tienne \ndans le fort au sud-est du village.\0");
    new->text[5] = strdup("Et un bouclier près de la tour de mage.\0");
    new->text[6] = strdup("Avec cet équipement, tu pourras facilement venir à bout du\n démon, alors va ! Pars à l'aventure et libère le royaume!\0");
    sfSprite_setTexture(new->animation_sprite, new->animation_texture, sfTrue);
    sfSprite_setTextureRect(new->animation_sprite, new->animation_rect);
    sfSprite_scale(new->animation_sprite, scale);
    push_to_back_dialogue(&rpg->dialogue, new);
}


void init_dialogue_2(rpg_t *rpg)
{
    dialogue_t *new = malloc(sizeof(dialogue_t));
    sfVector2f scale = {2.0, 2.0};

    set_default_value(new);
    new->animation_texture =
        sfTexture_createFromFile("assets/pnj/kingwinlu_faces.png", NULL);
    // Modifier le nombre de textes et les textes ici
    new->nb_text = 8;
    new->text = malloc(sizeof(char *) * 3);
    new->text[0] = strdup("Bonjour Roy! Tu ne te rappelles probablement pas de moi, \nni même de qui tu es.\0");
    new->text[1] = strdup("Malheureusement, beaucoup sont dans ton cas.\0");
    new->text[2] = strdup("Je suis le souverain légitime de ces terres que l'on \nappelle Valkyria, Jeremias.\0");
    new->text[3] = strdup("Cependant, je ne suis pas en mesure de me battre.\0");
    new->text[4] = strdup("C'est pour cela que je te demande de sauver le royaume des \ngriffes du démon Morgott.\0");
    new->text[5] = strdup("Pour t'aider dans ton aventure, va jeter un oeil au tableau \ndes quêtes au village.\0");
    new->text[6] = strdup("Tu trouveras des infos qui pourront t'aider à te préparer\n à ton combat.\0");
    new->text[7] = strdup("Je te souhaite bonne chance Roy, que le royaume de Valkyria \nsoit enfin sauvé du mal!\0");
    sfSprite_setTexture(new->animation_sprite, new->animation_texture, sfTrue);
    sfSprite_setTextureRect(new->animation_sprite, new->animation_rect);
    sfSprite_scale(new->animation_sprite, scale);
    push_to_back_dialogue(&rpg->dialogue, new);
}

void init_dialogue_3(rpg_t *rpg)
{
    dialogue_t *new = malloc(sizeof(dialogue_t));
    sfVector2f scale = {2.0, 2.0};

    set_default_value(new);
    new->animation_texture =
        sfTexture_createFromFile("assets/pnj/knightlow_faces.png", NULL);
    // Modifier le nombre de textes et les textes ici
    new->nb_text = 3;
    new->text = malloc(sizeof(char *) * 3);
    new->text[0] = strdup("Tiens, il n'y a qu'une seule affiche…\0");
    new->text[1] = strdup("'Rejoignez-moi au nord-ouest du village, près d'une petite\n chaumière.' Signé Ryia l'archère\0");
    new->text[2] = strdup("Comme je ne sais pas par où commencer, autant aller parler\n à cette archère.\0");
    sfSprite_setTexture(new->animation_sprite, new->animation_texture, sfTrue);
    sfSprite_setTextureRect(new->animation_sprite, new->animation_rect);
    sfSprite_scale(new->animation_sprite, scale);
    push_to_back_dialogue(&rpg->dialogue, new);
}

void init_dialogue(rpg_t *rpg)
{
    rpg->actual_dialogue = NULL;
    init_dialogue_1(rpg);
    init_dialogue_2(rpg);
    init_dialogue_3(rpg);
}