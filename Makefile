########################################################
# Makefile: I/D Cache and CPU makefile
########################################################
# 
# Author: Sehoon Kim
# Date:   2025-03-10
########################################################

# 컴파일러 설정
CC = g++

# 소스 파일과 출력 파일 설정
SRC = test.cpp
EXEC = test

# 기본 타겟 (실행 파일 생성)
all: run_test

# 실행 파일 만들기
build_test:
	$(CC) $(SRC) -o $(EXEC)

# clean: 빌드 파일 삭제
clean:
	rm -f $(EXEC)

run_test: build_test
