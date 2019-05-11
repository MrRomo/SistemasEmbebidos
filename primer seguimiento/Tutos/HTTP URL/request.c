#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t written;
    written = fwrite(ptr, size, nmemb, stream);
    return written;
}

int main () {
    CURL *curl;
    char *fp;
    CURLcode res;
    char *url = "http://www.rendergame.com";
    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",   curl_easy_strerror(res));

        curl_easy_cleanup(curl);

        //printf("\n%s", fp);
    }
    // return fp;
}