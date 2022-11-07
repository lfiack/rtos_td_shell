# TD FreeRTOS sur le Shell

## Amélioration du Shell
Le projet propre est disponible ici : https://github.com/lfiack/rtos_td_shell

### Ajout d'une structure
1. Listez les variables statiques
2. Dans le fichier **shell.h**, créez une structure nommée **h_shell_t**.
        Les membres de la structure correspondent aux variables statiques
3. Modifiez toutes les fonctions du shell qui manipulent les variables statiques pour qu'elles prennent comme premier paramètre un pointeur sur la structure **h_shell_t**
4. Modifiez le contenu des fonctions pour utiliser les membres de la structure à la place des variables statiques
5. Créez une instance statique de cette structure dans le main. Modifiez l'appel aux fonctions dans le main pour y ajouter la structure
6. Testez vos modifications.

### Driver UART
7. Dans le fichier **shell.h**, ajoutez la ligne suivante : 
```c
typedef uint8_t (* drv_shell_transmit_t)(char * pData, uint16_t size);
```
8. Qu'est-ce que ça signifie?
9. Faites de même pour la fonction **drv_shell_receive_t**
10. Créez la structure suivante:
```c
typedef struct drv_shell_struct
{
    drv_shell_transmit_t drv_shell_transmit;
    drv_shell_receive_t drv_shell_receive;
} drv_shell_t;
```
11. Ajoutez une instance de cette nouvelle structure dans la structure **h_shell_t**
12. Créez deux fichiers **drv_uart.c** et **drv_uart.h**.
13. Dans ces fichiers, créez deux fonctions :
```c
uint8_t drv_uart_receive(char * pData, uint16_t size);
uint8_t drv_uart_transmit(char * pData, uint16_t size);
```
14. Écrire le code de ces fonctions.
    Inspirez vous des fonctions 
```c
uart_read()
```
 et
```c
uart_write(char * s, uint16_t size)
``` 
dans **shell.c**

15. Dans **shell.c**, modifiez le code pour utiliser ces nouvelles fonctions à la place des anciennes
16. Modifiez le **main()** pour passer vos deux fonctions de driver à la structure du shell

### Intégration à FreeRTOS
17. Activez l'OS et démarrez le scheduler 
```c
vTaskStartScheduler();
```
18. Créez une tâche dans laquelle vous appellerez **shell_run()**
19. Modifiez le driver UART pour fonctionner avec interruptions. Utilisez une notification pour la synchronisation.
20. Testez.

