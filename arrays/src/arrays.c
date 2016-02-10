#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../include/arrays.h"

// LOOK INTO MEMCPY, MEMCMP, FREAD, and FWRITE

bool array_copy(const void *src, void *dst, const size_t elem_size, const size_t elem_count) {
	if( !src || !dst || elem_count == 0 || elem_size == 0)
		return false;
	void *dstReturn= memcpy(dst, src, (elem_count*elem_size));
	if(memcmp(dstReturn, dst, (elem_count*elem_size)) == 0)
		return true;
	else
		return false;
}

bool array_is_equal(const void *data_one, void *data_two, const size_t elem_size, const size_t elem_count) {
	if(!data_one || !data_two || elem_size == 0 || elem_count == 0)
		return false;
	if(memcmp(data_one, data_two, (elem_count*elem_size)) == 0)
		return true;
	else
		return false;
}

ssize_t array_locate(const void *data, const void *target, const size_t elem_size, const size_t elem_count) { 
	const char *dataTemp = (const char*) data;
	if(!data || !target || elem_size == 0 || elem_count == 0) {
		return -1;
	} else {
		for(int i = 0; i < elem_count; i++)
			if( memcmp((dataTemp+(i*elem_size)), target, elem_size) == 0)
				return i;
		return -1;
	}	
}

bool array_serialize(const void *src_data, const char *dst_file, const size_t elem_size, const size_t elem_count) {
	// const char* src_data_temp;
	FILE *fp;
	if(!src_data || !dst_file || elem_size == 0 || elem_count == 0 || *dst_file == '\0' || *dst_file == '\n')
		return false;
	else {
		//src_data_temp = (const char *)src_data;
		fp = fopen(dst_file, "w");
		if(!fp) {
			printf("Error..\n");
			return false;
		} else {
			fwrite(src_data, elem_count, elem_size, fp);
			fclose(fp);
			return true;
		 }
	}
}

bool array_deserialize(const char *src_file, void *dst_data, const size_t elem_size, const size_t elem_count) {
	FILE *fp;
	if(!src_file || !dst_data || elem_size == 0 || elem_count == 0 || *src_file == '\0' || *src_file == '\n')
		return false;
	else {
		fp = fopen(src_file, "r");
		if(!fp) {
			printf("Error on open\n");
			return false;
		} else {
			fread(dst_data, elem_size, elem_count, fp);
			return true;
		}

	}


}
