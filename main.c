#include <stdio.h>
#include <stdbool.h>

//#include <ncurses.h>
#include <argp.h>
#include "utils/color.h"

const char *argp_program_version = "CacheWiper v0.6.0";
const char *argp_program_bug_address = "<info.deadlyfirex@gmail.com>";
static char doc[] = "Your program description.";
static char args_doc[] = "[FILENAME]...";

static struct argp_option options[] = {
        {"scheduled", 's', 0, 0, "Perform a scheduled wipe."},
        {"force", 'f', 0, 0, "Do not ask for confirmation."},
        {"prompt", 'p', 0, 0, "Prompt for confirmation."},
        {"interactive", 'i', 0, 0, "Spawn a shell to choose what to wipe."},
        {"config", 'c', 0, 0, "Configure the application."},
        {0}
};

struct arguments {
    enum { FORCE, PROMPT } returnMode;
    enum { INTERACTIVE, CONFIG, STATIC } mode;
    bool isScheduled;
    char* filePath;
};

/*
   PARSER.
   Order of parameters: KEY, ARG, STATE.
*/
static error_t parse_opt(int key, char *arg, struct argp_state *state) {
    struct arguments *arguments = state->input;
    switch (key) {
        case 'p': arguments->returnMode = PROMPT; break;
        case 'f': arguments->returnMode = FORCE; break;
        case 'i': arguments->mode = INTERACTIVE; break;
        case 'c': arguments->mode = CONFIG; break;
        case 's': arguments->isScheduled = true; break;
        case ARGP_KEY_ARG: return 0;
        default: return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int main(int argc, char *argv[]) {
    struct arguments arguments;

    arguments.returnMode = PROMPT;
    arguments.mode = STATIC;
    arguments.isScheduled = false;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

//    if (argv[1] == NULL) {
//        printf(COLOR_RED COLOR_BOLD "error" COLOR_NORMAL ": no arguments received. (use -h for help)\n");
//    }
    printf("%s: %i\n", "Scheduled", arguments.isScheduled);
    printf("%s: %i\n", "Mode", arguments.mode);
    printf("%s: %i\n", "Return mode", arguments.returnMode);
    return 0;
}
