# Git 101

!> Work in process!

```git

git help
git init //init project, creates .git folder
git add . //add everythink in dir to staga
git commit -m "some describe commit message" //save changes

summary:
- make change
- add changes
- commit changes to the repo with msg


git log //list all comits
args:
-n 1 //return 1 commit
--since=2018.08.13
--until=2018.08.13
--author="name"
--grep="word" //search in commit messages

git status // report between dir and repository
git diff // difference between file vers
git rm file //delete file after we delete if from filesystem
git checkout // pull down from repository
git commit --amend -m "msg" //edit last commit msg, add files from stage
notepad .gitignore // file to specify files/dir to be ignored
git rm --cached filename //remove track of file that been tracked
git rouch .gitkeep //add file to empty dir to track
git ls -tree heap // return list of a tree obj
git log --oneline //log commits, oneline each
git log --stat --summary // summary log report
git log --graph
git branch //list of branches
git checkout -b branchname // creates and switch to a new branch
git diff branchname..branchname //shows branch difference
git branch -m oldbranchname newbranchname //rename branche
git branch -d branchnametodelete //delete branch
git merge branchname //merge current branch with given branch
git merge --abort //cancel merge
git branch --merged
git stash save "msg"
git stash list
git stash pop //get stash and remove it from there
git stash apply //apply stash
git stash drop //delete stash
git stash clear
git remote
git remote add origin uld //add remote with name origin
cat .git/config
git remote rm origin //remove remote with name origin
git push origin branchname
git clone url
git fetch origin
git merge origin/master
git pull

aliases:
.gitconfig



```



TODO: typical workflow with git (branch, merge etc...)