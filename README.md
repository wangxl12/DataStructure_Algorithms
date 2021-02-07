# DataStructure_Algorithms
Nothing special in readme ... in this repository i just review all the datastructure as well as algorithms needed in graduate MBA
# Git分支简介

https://git-scm.com/book/zh/v2/Git-%E5%88%86%E6%94%AF-%E5%88%86%E6%94%AF%E7%AE%80%E4%BB%8B
git在执行命令`git init`指令的之后就会自动创建一个分支master，master分支和其他的自己新建的分支相比没有什么特殊的地方。
- 创建分支：\n
git branch <branch name>

- 查看各个分支所指向的对象
git log --oneline --decorate

- 切换分支
git checkout <branch name>

- 输出你的提交历史、各个分支的指向以及项目的分支分叉情况。
git log --oneline --decorate --graph --all

- 查看所有的现有分支
git branch -a

- 查看更改
git status

- 查看当前分支
git branch

## ...or create a new repository on the command line

`echo "# -" >> README.md`

`git init  # to transfer the current file to repository`

`git add .  # to add all the changes `

`git commit -m "first commit"  # to commit the all files to local repository`

`git branch -M main`

`git remote add origin https://github.com/wangxl12/DataStructure_Algorithms.git`

`git push -u origin main`


## ...or push an existing repository from the command line 

`git remote add origin https://github.com/wangxl12/DataStructure_Algorithm.git`

`git branch -M main`

`git push -u origin main`
