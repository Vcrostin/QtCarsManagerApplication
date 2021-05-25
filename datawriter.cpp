#include "datawriter.h"

DataWriter::DataWriter(const std::string &file_name):stream_output(file_name){

}

DataWriter::~DataWriter(){
    stream_output.close();
}


int DataWriter::DataSource(const std::string& str){
    if(stream_output.is_open())
        stream_output.close();
    stream_output.open(str);
    return 1;
}
