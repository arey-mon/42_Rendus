# PRINCIPAL COMMMANDS

. mov 
mov R0 R1 ; where R0 is opérandicible (copy stock) and R1 opérandesource (copy value)
. jmp : aller à l'adresse
. cmp : compare variables
. syscall
back up and check errors
returns 0 if success, -1 if error
. je : is setting variable = 0
. ret : quitte la procédure en cours
. inc || dec : increase || decrease
. push : indiquer une valeur ou une opérande qui sera ajoutée à la pile
. pop : récupère le contenu de la pile et le stocke dans le registre
. cl : used with mov to only affect 8 bits (one char)

# REGISTRES
[EAX] || [RAX] sont les registres généraux. EAX = 32 bits, RAX = 64 bits
[RAX] : registre général, celui que l'on incrémente en premier dans la norme
[RBX] : registre général
[RSI] : adresse source
[RDI] : adresse de destination.
Les registres sont des espaces mémoires dans le coeur du processeur
[EAX] should contain return value

# COMPILE COMMANDS
declare in your .s global function_name;
then select function_name as starting point of function;
make
gcc *.c *.h *.a
