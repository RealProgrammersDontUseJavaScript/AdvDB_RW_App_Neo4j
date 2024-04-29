#include <neo4j-client.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char** argv) {
	neo4j_client_init(); // This initializes the neo4j-client lib

	neo4j_connection_t *RW_App_Conn = neo4j_connect("neo4j://neo4j:GraphDBsSuck@localhost:7687", NULL, NEO4J_INSECURE);
	if(RW_App_Conn == NULL) { neo4j_perror(stderr, errno, "Connection failed"); return EXIT_FAILURE; }

	neo4j_result_stream_t *results = neo4j_run(RW_App_Conn, "RETURN 'hello world'", neo4j_null);
	if(results == NULL) { neo4j_perror(stderr, errno, "Failed to run statement"); return EXIT_FAILURE; }

	neo4j_result_t *result = neo4j_fetch_next(results);
	if(result == NULL) { neo4j_perror(stderr, errno, "Failed to fetch result"); return EXIT_FAILURE; }

	neo4j_value_t value = neo4j_result_field(result, 0);
	char buf[128];
	printf("%s\n", neo4j_tostring(value, buf, sizeof(buf)));

	neo4j_close_results(results);
	neo4j_close(RW_App_Conn);
	neo4j_client_cleanup();
	return EXIT_SUCCESS;
}

