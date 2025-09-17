알겠습니다. Git의 핵심 기능들을 마크다운 파일로 보기 좋게 정리해 드릴게요. 이 내용을 복사해서 git_cheatsheet.md 와 같이 파일로 저장해두고 사용하시면 편리합니다.

Git & GitHub 핵심 명령어 요약
이 문서는 Git을 사용하여 로컬 프로젝트를 GitHub 원격 저장소에 연결하고 관리하는 기본적인 명령어들을 정리한 치트 시트입니다. 🧑‍💻

1. 원격 저장소 연결 및 관리
✅ 새 원격 저장소 연결하기
로컬 저장소를 GitHub에 생성한 새 원격 저장소와 처음 연결할 때 사용합니다.

Bash

# 'origin'이라는 이름으로 원격 저장소 주소를 등록합니다.
# 일반적으로 이 이름(origin)을 그대로 사용합니다.
git remote add origin [원격 저장소 URL]

# 예시
git remote add origin https://github.com/user/my-project.git
🔗 연결된 원격 저장소 확인하기
현재 어떤 원격 저장소가 연결되어 있는지 주소를 확인할 수 있습니다.

Bash

git remote -v
✂️ 기존 원격 저장소 연결 끊기
연결을 잘못했거나, 다른 원격 저장소로 변경하고 싶을 때 사용합니다.

Bash

git remote remove origin
2. 작업 내용 기록 및 업로드 (Add, Commit, Push)
로컬에서 수정한 내용을 GitHub에 올리는 가장 일반적인 3단계 과정입니다.

➕ git add : 변경된 파일 선택하기
로컬에서 수정된 파일들 중, 저장소에 기록(Commit)할 파일들을 **선택(Staging)**하는 단계입니다.

Bash

# 특정 파일 하나만 선택
git add 파일이름.txt

# 현재 디렉토리의 모든 변경사항을 선택 (가장 많이 사용)
git add .
💾 git commit : 변경 내용 기록하기
선택(Staging)된 파일들의 변경사항에 대해 **하나의 의미 있는 작업 단위(버전)**로 묶고, 설명을 붙여 로컬 저장소에 기록합니다.

Bash

# -m 옵션 뒤에 따옴표를 사용하여 커밋 메시지를 작성합니다.
git commit -m "여기에 변경 내용에 대한 요약을 적습니다"

# 예시
git commit -m "로그인 기능 추가 완료"
🚀 git push : 원격 저장소에 업로드하기
로컬 저장소에 기록(Commit)된 내용을 GitHub 원격 저장소로 업로드하여 다른 사람들과 공유할 수 있게 합니다.

Bash

# 'origin'이라는 원격 저장소의 'main' 브랜치로 푸시합니다.
git push origin main
💡 최초 Push 꿀팁!

처음 push 할 때 -u 옵션을 추가하면, 다음부터는 git push 명령어만 입력해도 자동으로 origin의 main 브랜치로 push 됩니다.

Bash

git push -u origin main
