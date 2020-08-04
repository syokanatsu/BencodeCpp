#include "bencode.h"

#define TORRENT_FILE_NAME "0B35A9A31C2AF8A05183A3FAF210CE9CAB7898F3.torrent"

int main() {

	Bencode::Value root;
	Bencode::Reader reader;
	FILE* fp = nullptr;
	fopen_s(&fp, TORRENT_FILE_NAME, "rb");
	std::vector<char> doc;
	int sum;
	fseek(fp, 0, SEEK_END);
	sum = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	doc.resize(sum);
	fread(&doc[0], 1, sum, fp);
	reader.parse(&doc[0], &doc[0] + sum, root);



	return 0;
}