#include<iostream>
#include<Windows.h>
#include<string>
#pragma comment(lib, "winmm.lib")
using namespace std;

//global variables
int health = 100;
string inventory[10];
bool chest1 = false;

//funciton declarations
void BattleSystem();
int MonsterGen();
void FinalBoss();
void ItemDropper();

int main() {//starting pt of program
    srand(time(NULL)); //randomizes the seed

system("color 02");   //change color of screen and text
system("pause");

//PlaySound(TEXT("music.wav"), NULL, SND_FILENAME | SND_ASYNC);     //play music or sound effects (download a wav file)

    for (int i = 0; i < 10; i++)
        inventory[i] = " ";

    int room = 1;
    char input = 'a';
    bool restart = true;
    cout << R"(
   ______     __     __     ______     __   __     ______        ______     ______     __    __     ______    
  /\  ___\   /\ \  _ \ \   /\  __ \   /\ "-.\ \   /\  ___\      /\  ___\   /\  __ \   /\ "-./  \   /\  ___\  
  \ \  __\   \ \ \/ ".\ \  \ \  __ \  \ \ \-.  \  \ \___  \     \ \ \__ \  \ \  __ \  \ \ \-./\ \  \ \  __\  
   \ \_____\  \ \__/".~\_\  \ \_\ \_\  \ \_\\"\_\  \/\_____\     \ \_____\  \ \_\ \_\  \ \_\ \ \_\  \ \_____\
    \/_____/   \/_/   \/_/   \/_/\/_/   \/_/ \/_/   \/_____/      \/_____/   \/_/\/_/   \/_/  \/_/   \/_____/

    )" << endl;
    while (restart == true) { //super game loop

        while (health >= 0 && input != 'q') { //main game loop



            switch (room) {
            case 1:
                cout << "You wake up in a cave." << endl;
                cout << "You can not remember how you got there." << endl;
                cout << "You look up and see light." << endl;
                cout << "You must have fallen in to the cave" << endl;
                cout << "You can not climb back up" << endl;
                cout << "Look around? (l)" << endl;
                cin >> input;
                if (input == 'l') {
                    cout << "You see a skeleton. it looks like they fell down too." << endl;
                    cout << "Go to the Skeleton (s)." << endl;
                    cin >> input;
                    if (input == 's') {
                        cout << "You crawl over to the skeleton" << endl;
                        cout << "The skeleton has a wooden shield and a rusty sword, you can not carry both of them." << endl;
                        cout << "Choose one: (1) to take shield, (2) to take sword" << endl;
                        cin >> input;
                        if (input == '1') {
                            cout << "you take the shield, it will reduce damage from possible enemies" << endl;
                            inventory[0] = "shield";
                            room = 2;

                        }
                        else if (input == '2') {
                            cout << "you take the sword, it will increase your attack power" << endl;
                            inventory[0] = "sword";
                            room = 2;

                            //cout << "your inventory:" << endl;
                            //for (int i = 0; i < 5; i++)
                             //cout << inventory[i] << " ";


                        }

                    }
                }
                cout << "your inventory: " << endl;
                for (int i = 0; i < 10; i++)
                    cout << inventory[i] << " ";
                break;

            case 2:
                cout << "" << endl;
                cout << "you see a fissure in the wall, a draft is blowing through it, there is probably a cavern on the other end" << endl;
                cout << "you enter the fissure (f)" << endl;
                cin >> input;
                if (input == 'f')
                    room = 3;
                break;
            case 3:

                cout << "You enter a large cavern, there is monster in the corner" << endl;
                BattleSystem(); //battle
                //getchar();
                if (health <= 0)
                    break;
                cout << "you are wounded from your fight. progress to next chamber? (n)" << endl;
                cin >> input;
                if (input == 'n') {
                    room = 4;
                }
                break;
            case 4:
                cout << "In the next chamber you find a pool of water, next to it a patch of mushrooms is growing. You take a suspicious mushroom and eat it." << endl;
                health += 30;
                cout << "your health is now " << health << endl;
                cout << "Move to the next chamber? (n)" << endl;
                cin >> input;
                if (input == 'n')
                    room = 5;
                break;
            case 5:
                cout << "You enter the next chamber and see storage crates." << endl;
                cout << "The monsters must have a whole colony down here." << endl;
                cout << "One of the crates has a crack in it, you can probably pry it open" << endl;
                cout << "Open the crate? (o) or leave to next chamber. (n)" << endl;
                cin >> input;
                if (input == 'n')
                    room = 6;
                else if (input == 'o')
                    if (chest1 == false) {
                        ItemDropper();
                        cout << "This item might help you with combat." << endl;
                        cout << "You take the item and move to the next chamber" << endl;
                        chest1 = true;
                        room = 6;
                    }
                    else {
                        cout << "the chest is empty" << endl;
                    }

                break;
            case 6: //battle
                cout << "You enter the next chamber and are ambushed by a monster!" << endl;
                BattleSystem();
                //getchar();
                if (health <= 0)
                    break;
                cout << "you are wounded from your fight. progress to next chamber? (n)" << endl;
                cin >> input;
                if (input == 'n')
                    room = 7;
                break;
            case 7: //battle
                cout << "you crawl into the next chamber hoping there isnt a monster in it, but you get attacked by another monster! (n)" << endl;
                BattleSystem();
                //getchar();
                if (health <= 0)
                    break;
                cout << "you are wounded from your fight. progress to next chamber? (n)" << endl;
                cin >> input;
                if (input == 'n')
                    room = 8;
                break;
            case 8:
                cout << "you find another storage room, you rest there and bandage you wounds." << endl;
                health += 100;
                cout << "your health is now " << health << endl;
                cout << "after you heal you decide to keep moving." << endl;
                cout << "progress to next chamber? (n)" << endl;
                cin >> input;
                if (input == 'n')
                    room = 9;
                break;
            case 9: {
                cout << "You see a bright light shining down from the ceiling." << endl;
                cout << "You finally have a chance to escape, But a huge troll is blocking your escape." << endl;
                cout << "You will have to defeat it to escape!" << endl;
                cout << "Begin fight! (b) or give up (g)" << endl;
                cin >> input;
                if (input == 'b') {
                    FinalBoss(); //battle
                    if (health >= 0)
                        room = 10;
                }
                else if (input == 'g')
                    restart = false;
                break;
            }
            case 10:
                cout << "You defeat the monster!" << endl;
                cout << "You move over its body and climb up into the light." << endl;
                cout << "you reach the surface. you climbed out of a well in the middle of a village." << endl;
                cout << "The villagers give you food and water and even know where you live" << endl;
                health += 70;
                cout << "after you have rested you start the journey back to your home" << endl;
                cout << "continue...(c)" << endl;
                cin >> input;
                if (input == 'c')
                    room = 11;
                break;
            case 11:
                cout << "While walking back you trip and fall into a hole in the ground" << endl;
                room = 1;
                break;

            }
        }//end of game loop

        if (health <= 0) {
            cout << "you DIED!" << endl;
            cout << "restart? y/n" << endl;
            Beep(350, 800);
            Beep(300, 800);
            Beep(270, 1000);
            cin >> input;
            if (input == 'y')
                cout << "restarting..." << endl;
            else
                cout << "thanks for playing!" << endl;
            restart = false;
        }
    }//end of the super game loop

}//end of main

int MonsterGen() {
    int num = rand() % 100;
    if (num < 50) {
        cout << "A Goblin spawns" << endl;
        return 1;
    }
    else {
        cout << "A Orc spawns" << endl;
        return 2;
    }
}

void FinalBoss() {
    cout << "A giant troll apears" << endl;
    int FinalBossHealth = 75;
    cout << "The final fight begins" << endl;

    int MonsterAtk = 0;

    while (FinalBossHealth > 0 && health > 0) {
        char input;

        MonsterAtk = rand() % 50;

        if (inventory[0] == "shield") {
            cout << "The monster attacks! you block some of its damage" << endl;
            if (MonsterAtk > 10)
                health -= MonsterAtk - 10;
          
        }
        if (inventory[0] == "shield" && inventory[2] == "armor1")
            MonsterAtk -= 20;
        if (inventory[0] == "shield" && inventory[3] == "armor2")
            MonsterAtk -= 35;


        else if (inventory[2] == "armor1") {
            cout << "The monster attacks! you block some of its damage" << endl;
            MonsterAtk -= 5;
        }
        else if (inventory[3] == "armor2") {
            cout << "The monster attacks! you block some of its damage" << endl;
            MonsterAtk -= 15;
        }


        //----------------------------------------------------------
        if (inventory[5] == "bow") {
            cout << "you shoot the monster with your bow! +100 dmg" << endl;
            FinalBossHealth -= 100;
        }
        else if (inventory[1] == "spear") {
            cout << "you attack the monster with your spear! +20 dmg" << endl;
            FinalBossHealth -= 20;
        }
        else if (inventory[0] == "sword") {
            cout << "you attack the monster with your sword! +15 dmg" << endl;
            FinalBossHealth -= 15;
        }
        
        else if (inventory[4] == "bone") {
            cout << "you attack the monster with your bone! +10 dmg" << endl;
            FinalBossHealth -= 10;
        }
        else {
            cout << "you attack the monster with your fists! +5 dmg" << endl;
            FinalBossHealth -= 5;
        }
        //---------------------------------------------------------

        cout << "your health is now " << health << ", and the monsters health is now " << FinalBossHealth << endl;
        system("pause");

        health -= MonsterAtk;
        if (health > 0 && FinalBossHealth > 0) { //check to make sure nobody is dead before giving choices
            cout << "you can fight (f), or run (r)!" << endl;
            cin >> input;
            if (input == 'r') {
                int num = rand() % 100;
                if (num < 40) {
                    cout << "you escape the battle" << endl;
                    break;
                }
                else
                    cout << "you failed to escape" << endl;
            }

            if (input == 'f') cout << "the battle continues..." << endl;
        } //end of player choice

    }//end of battle loop

    if (FinalBossHealth <= 0)
        cout << "You defeat the boss!" << endl;

    else
        cout << "you DIED" << endl;
    Beep(350, 800);
    Beep(300, 800);
    Beep(270, 1000);
}

void BattleSystem() {
    cout << "The fight begins" << endl;

    int MonsterType = MonsterGen();
    int MonsterHealth = 0;
    int MonsterAtk = 0;
    if (MonsterType == 1)
        MonsterHealth = 20;
    else if (MonsterType == 2)
        MonsterHealth = 30;


    while (MonsterHealth > 0 && health > 0) {
        char input;
        if (MonsterType == 1)
            MonsterAtk = rand() % 10;
        else if (MonsterType == 2)
            MonsterAtk = rand() % 15;
       
        if (inventory[0] == "shield") {
            cout << "The monster attacks! you block some of its damage" << endl;
            if (MonsterAtk > 10)
                health -= MonsterAtk - 10;
            else health -= MonsterAtk;
        }
        if (inventory[0] == "shield" && inventory[2] == "armor1")
            MonsterAtk -= 20;
        if (inventory[0] == "shield" && inventory[3] == "armor2")
            MonsterAtk -= 35;


        else if (inventory[2] == "armor1") {
            cout << "The monster attacks! you block some of its damage" << endl;
            MonsterAtk -= 5;
        }
        else if (inventory[3] == "armor2") {
            cout << "The monster attacks! you block some of its damage" << endl;
            MonsterAtk -= 15;
        }

     
        //int damage{};
        //---------------------------------------------------------------
        else if (inventory[5] == "bow") {
            cout << "you shoot the monster with your bow! +100 dmg" << endl;
            MonsterHealth -= 100;
        }
        else if (inventory[1] == "spear") {
            cout << "you attack the monster with your spear! +20 dmg" << endl;
            MonsterHealth -= 20;
        }
        if (inventory[0] == "sword") {
            cout << "you attack the monster with your sword! +15 dmg" << endl;
            MonsterHealth -= 15;
        }
        else if (inventory[4] == "bone") {
            cout << "you attack the monster with your bone! +10 dmg" << endl;
            MonsterHealth -= 10;
        }
        else {
            cout << "you attack the monster with your fists! +5 dmg" << endl;
            MonsterHealth -= 5;
        }
        //-----------------------------------------------------------
        //cout << "you attack the monster! + " << damage << "dmg" << endl;
        //MonsterHealth -= damage;

        cout << "your health is now " << health << ", and the monsters health is now " << MonsterHealth << endl;
        system("pause");

        health -= MonsterAtk;
        if (health > 0 && MonsterHealth > 0) { //check to make sure nobody is dead before giving choices
            cout << "you can fight (f), or run (r)!" << endl;
            cin >> input;
            if (input == 'r') {
                int num = rand() % 100;
                if (num < 40) {
                    cout << "you escape the battle" << endl;
                    break;
                }
                else
                    cout << "you failed to escape" << endl;
                Beep(350, 800);
                Beep(300, 800);
                Beep(270, 1000);
            }

            if (input == 'f') cout << "the battle continues..." << endl;
        } //end of player choice



    }//end of battle loop

    if (health <= 0)
        cout << "you DIED" << endl;

    else
        cout << "you survived" << endl;   
    Beep(350, 800);
    Beep(300, 800);
    Beep(270, 1000);

}//end of battle function

void ItemDropper() {
    int num = rand() % 100;
    if (num < 25) {
        cout << "you got a spear" << endl;
        inventory[1] = "spear";
    }
    else if (num < 50) {
        cout << "you got a metal helmet" << endl;
        inventory[2] = "armor1";
    }
    else if (num < 75) {
        cout << "you got an metal chestplate" << endl;
        inventory[3] = "armor2";
    }
    else if (num < 99) {
        cout << "you got an old bone" << endl;
        inventory[4] = "bone";
    }
    else if (num < 100) {
        cout << "you got lucky! you found a crossbow" << endl;
        cout << "(this was a 1% chance btw)" << endl;
        inventory[5] = "bow";
    }
    else {
        cout << "you got nothing" << endl;
    }
}
