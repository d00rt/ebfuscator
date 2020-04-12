#define CHECK_ERROR_CODE(TARGET) { \
    DWORD last_error = GetLastError(); \
	if ( last_error == (TARGET) ) { \
		printf("[+] SUCESS ON ERROR: %d\n", (int)(TARGET)); \
	} \
	else { \
		printf("[!] ERROR %d DOESNT MATCH WITH LAST ERROR %d\n", (int)(TARGET), (int)last_error); \
	} \
}

void generate_error_1(void);
void generate_error_2(void);
void generate_error_3(void);
void generate_error_5(void);
void generate_error_6(void);
void generate_error_18(void);
void generate_error_32(void);
void generate_error_126(void);
