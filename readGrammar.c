#include "parser.h"

void printList(Term* head)
{
    while(head)
    {
        if(head->is_term==0) printf("%d -> ", head->type.nt);
        else printf("%d -> ", head->type.tok);
        
        head = head->next;
    }
}

char* removeFirstAndLast(char* s)
{
    if(strlen(s) < 2 || s[0] != '<') return s;
    if(s[strlen(s)-1] == '\n') s[strlen(s)-1] = '\0';
    if(s[strlen(s)-1] == '>') s[strlen(s)-1] = '\0';
    return s+1;
}

TermType getType(char * word, int * tag) {
    int temp_tag = -1;
    TermType type;

    if(strcmp(word, "program") == 0) {temp_tag = 0; type.nt = PROGRAM;}
    if(strcmp(word, "decl_list") == 0) {temp_tag = 0; type.nt = DECL_LIST;}
    if(strcmp(word, "assgn_list") == 0) {temp_tag = 0; type.nt = ASSGN_LIST;}
    if(strcmp(word, "decl_stmt") == 0) {temp_tag = 0; type.nt = DECL_STMT;}
    if(strcmp(word, "assgn_stmt") == 0) {temp_tag = 0; type.nt = ASSGN_STMT;}
    if(strcmp(word, "index") == 0) {temp_tag = 0; type.nt = INDEX;}
    if(strcmp(word, "rng") == 0) {temp_tag = 0; type.nt = RNG;}
    if(strcmp(word, "type") == 0) {temp_tag = 0; type.nt = TYPE;}
    if(strcmp(word, "array_range") == 0) {temp_tag = 0; type.nt = ARRAY_RANGE;}
    if(strcmp(word, "dtype") == 0) {temp_tag = 0; type.nt = DTYPE;}
    if(strcmp(word, "one_or_more_var") == 0) {temp_tag = 0; type.nt = ONE_OR_MORE_VAR;}
    if(strcmp(word, "listvar") == 0) {temp_tag = 0; type.nt = LISTVAR;}
    if(strcmp(word, "singlevar_dec") == 0) {temp_tag = 0; type.nt = SINGLEVAR_DEC;}
    if(strcmp(word, "multivar_dec") == 0) {temp_tag = 0; type.nt = MULTIVAR_DEC;}
    if(strcmp(word, "jagged2_dec") == 0) {temp_tag = 0; type.nt = JAGGED2_DEC;}
    if(strcmp(word, "jagged3_dec") == 0) {temp_tag = 0; type.nt = JAGGED3_DEC;}
    if(strcmp(word, "jagged2_init") == 0) {temp_tag = 0; type.nt = JAGGED2_INIT;}
    if(strcmp(word, "jagged3_init") == 0) {temp_tag = 0; type.nt = JAGGED3_INIT;}
    if(strcmp(word, "jagged2_idx") == 0) {temp_tag = 0; type.nt = JAGGED2_IDX;}
    if(strcmp(word, "jagged3_idx") == 0) {temp_tag = 0; type.nt = JAGGED3_IDX;}
    if(strcmp(word, "jagged2_rng") == 0) {temp_tag = 0; type.nt = JAGGED2_RNG;}
    if(strcmp(word, "jagged3_rng") == 0) {temp_tag = 0; type.nt = JAGGED3_RNG;}
    if(strcmp(word, "jagged2_single_init") == 0) {temp_tag = 0; type.nt = JAGGED2_SINGLE_INIT;}
    if(strcmp(word, "jagged3_single_init") == 0) {temp_tag = 0; type.nt = JAGGED3_SINGLE_INIT;}
    if(strcmp(word, "expression") == 0) {temp_tag = 0; type.nt = EXPRESSION;}
    if(strcmp(word, "array_sel") == 0) {temp_tag = 0; type.nt = ARRAY_SEL;}
    if(strcmp(word, "var") == 0) {temp_tag = 0; type.nt = VAR;}
    if(strcmp(word, "array_idx") == 0) {temp_tag = 0; type.nt = ARRAY_IDX;}
    if(strcmp(word, "arithmetic_exp") == 0) {temp_tag = 0; type.nt = ARITHMETIC_EXP;}
    if(strcmp(word, "boolean_exp") == 0) {temp_tag = 0; type.nt = BOOLEAN_EXP;}
    if(strcmp(word, "term") == 0) {temp_tag = 0; type.nt = TERM;}
    if(strcmp(word, "factor") == 0) {temp_tag = 0; type.nt = FACTOR;}
    if(strcmp(word, "l_or_term") == 0) {temp_tag = 0; type.nt = L_OR_TERM;}
    if(strcmp(word, "l_and_term") == 0) {temp_tag = 0; type.nt = L_AND_TERM;}
    if(strcmp(word, "e") == 0) {temp_tag = 0; type.nt = EPSILON;}

    type.tok.lexeme[0] = '\0';
    type.tok.line_num = 0;
    type.tok.next = NULL;

    if(strcmp(word, "BO") == 0) {temp_tag = 1; type.tok = BO;}
    if(strcmp(word, "BC") == 0) {temp_tag = 1; type.tok = BC;}
    if(strcmp(word, "SQO") == 0) {temp_tag = 1; type.tok = SQO;}
    if(strcmp(word, "SQC") == 0) {temp_tag = 1; type.tok = SQC;}
    if(strcmp(word, "CURLO") == 0) {temp_tag = 1; type.tok = CURLO;}
    if(strcmp(word, "CURLC") == 0) {temp_tag = 1; type.tok = CURLC;}
    if(strcmp(word, "CLN") == 0) {temp_tag = 1; type.tok = CLN;}
    if(strcmp(word, "SEMCOL") == 0) {temp_tag = 1; type.tok = SEMCOL;}
    if(strcmp(word, "ROP") == 0) {temp_tag = 1; type.tok = ROP;}
    if(strcmp(word, "ASSGN") == 0) {temp_tag = 1; type.tok = ASSGN;}
    if(strcmp(word, "KEY_PROG") == 0) {temp_tag = 1; type.tok = KEY_PROG;}
    if(strcmp(word, "KEY_DECL") == 0) {temp_tag = 1; type.tok = KEY_DECL;}
    if(strcmp(word, "KEY_LIST") == 0) {temp_tag = 1; type.tok = KEY_LIST;}
    if(strcmp(word, "KEY_OF") == 0) {temp_tag = 1; type.tok = KEY_OF;}
    if(strcmp(word, "KEY_VARS") == 0) {temp_tag = 1; type.tok = KEY_VARS;}
    if(strcmp(word, "KEY_ARR") == 0) {temp_tag = 1; type.tok = KEY_ARR;}
    if(strcmp(word, "R1") == 0) {temp_tag = 1; type.tok = R1;}
    if(strcmp(word, "KEY_SIZE") == 0) {temp_tag = 1; type.tok = KEY_SIZE;}
    if(strcmp(word, "KEY_VALS") == 0) {temp_tag = 1; type.tok = KEY_VALS;}
    if(strcmp(word, "KEY_JAG") == 0) {temp_tag = 1; type.tok = KEY_JAG;}
    if(strcmp(word, "KEY_INT") == 0) {temp_tag = 1; type.tok = KEY_INT;}
    if(strcmp(word, "KEY_REAL") == 0) {temp_tag = 1; type.tok = KEY_REAL;}
    if(strcmp(word, "KEY_BOOL") == 0) {temp_tag = 1; type.tok = KEY_BOOL;}
    if(strcmp(word, "OP_PLUS") == 0) {temp_tag = 1; type.tok = OP_PLUS;}
    if(strcmp(word, "OP_MINUS") == 0) {temp_tag = 1; type.tok = OP_MINUS;}
    if(strcmp(word, "OP_STAR") == 0) {temp_tag = 1; type.tok = OP_STAR;}
    if(strcmp(word, "OP_SLASH") == 0) {temp_tag = 1; type.tok = OP_SLASH;}
    if(strcmp(word, "OP_AND") == 0) {temp_tag = 1; type.tok = OP_AND;}
    if(strcmp(word, "OP_OR") == 0) {temp_tag = 1; type.tok = OP_OR;}
    if(strcmp(word, "ID") == 0) {temp_tag = 1; type.tok = ID;}
    if(strcmp(word, "INT") == 0) {temp_tag = 1; type.tok = INT;}

    if(tag) *tag = temp_tag;
    return type;
}

Term* addNode(Term* head, char* word) // inserts node at end of linked list
{
    Term* last = head;
    Term* new = (Term*) malloc(sizeof(Term));
    new->next == NULL;
    new->type = getType(word, &(new->is_term));
    if(new->is_term == -1) printf("Unknown Symbol : %s!\nTerrible error\nLike North Indian filter coffee\nShould abort\n",word);
    if(!head) return new;
    while(last->next) last=last->next;
    last->next = new;
    return head;
}


void readGrammar(char *filename, Grammar* g)
{
    FILE *text = fopen(filename, "r");
    char line[150];
    g->num_rules = 0;
    int size_lim = 1;
    g->rules = (Term **) malloc(size_lim * sizeof(Term *));
    while (fgets(line, 150, text) != NULL)
    {
        if(line[0]=='\n') continue;
        // printf("%s", line);
        if(g->num_rules == size_lim) {
            size_lim *= 2;
            g->rules = (Term **) realloc(g->rules, size_lim * sizeof(Term *));
        }

        char *token;
        int success;
        token = strtok(line, " ");
        token = removeFirstAndLast(token); // strip '<' and '>'
        g->rules[g->num_rules]->type.nt = getType(token, &success).nt;
        if(success <= 0) printf("Error\nSup Rohit! You're the one most likely to see this\n");
        g->rules[g->num_rules]->is_term = success;
        g->rules[g->num_rules]->next = NULL;
        //token = strtok(NULL, " ");
        //printf("\n");
        while((token = strtok(NULL, " "))!= NULL) 
        {
            token[strcspn(token, "\n")] = 0;
            if(!strlen(token)) continue; // strings with length 0 found
            //printf("%s,", token);
            token = removeFirstAndLast(token);
            g->rules[g->num_rules] = addNode(g->rules[g->num_rules], token);
            //token = strtok(NULL, " ");
        }
        (g->num_rules)++;
    }
    g->rules = (Term **) realloc(g->rules, g->num_rules);
}

Term** get_rules(Grammar* g, TermType t, int* num_rules) // returns pointer to an array of linkedlists
{
    int j = 0;
    for(int i=0;i<g[0].num_rules;i++) if(g->rules[i]->type.nt == t.nt) j++;
    Term** req = (Term**) malloc(j * sizeof(Term*));
    int count = 0;
    for(int i=0;i<g[0].num_rules;i++) if(g->rules[i]->type.nt == t.nt) req[count++]=g->rules[i]->next;
    if(num_rules) *num_rules = j;
    if(j==0) printf("NO RULES FOUND FOR GIVEN NON-TERMINAL!\nIS THIS A TERMINAL??\nABORT NOW!!");
    return req;
}	


int main()
{
    Grammar g[100];
    readGrammar("grammar.txt",g);
    //printList(g[15].next);
    TermType t = {MULTIVAR_DEC};
    int num_rules;
    Term** rules = get_rules(g,t,&num_rules);
    printf("num rules = %d\n", num_rules);
    int i=0;
    while(i<num_rules)
    {
        printList(rules[i++]);
        printf("\n");
    }
}