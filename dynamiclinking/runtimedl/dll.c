#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
// vector.h 파일을 사용하지않음
int x[2] = {1, 2};
int y[2] = {3, 4};
int z[2];

int main() {
    void *handle;
    void (*addvec)(int *, int *, int *, int);
    char *error;

    // (1) (dlopen)라이브러리 로드 //만들어둔 shared library를 로드
    handle = dlopen("./libvector.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    // (2) 함수 주소 조회
    addvec = (void (*)(int *, int *, int *, int)) dlsym(handle, "addvec");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    // (3) 함수 호출
    addvec(x, y, z, 2);
    printf("z = [%d %d]\n", z[0], z[1]);

    // (4) 라이브러리 언로드
    if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    return 0;
}
