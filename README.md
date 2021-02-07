# DataStructure_Algorithms
Nothing special in readme ... in this repository i just review all the datastructure as well as algorithms needed in graduate MBA  
# Git分支简介  
https://git-scm.com/book/zh/v2/Git-%E5%88%86%E6%94%AF-%E5%88%86%E6%94%AF%E7%AE%80%E4%BB%8B  
git在执行命令`git init`指令的之后就会自动创建一个分支master，master分支和其他的自己新建的分支相比没有什么特殊的地方。这里所说的master是以前的版本有，但是现在为了某种原因，需要在初始化仓库之后，将master强制转换为main，即命令`git branch -M main`的作用。  
# 关联本地分支与远程分支  
https://www.cnblogs.com/a-flydog/p/5520999.html  
`git pull origin master:feature-wxDemo`    #git pull <远程主机名> <远程分支名>:<本地分支名>  
# 本地分支与远程分支的关系
https://blog.csdn.net/techflow/article/details/109352820  
# git branch用法总结，查看、新建、删除、重命名  
https://blog.csdn.net/afei__/article/details/51567155  
origin即远程仓库的别名  
# 如何看log（这篇博客教会了我学会了如何版本控制与分支的合并）  
https://www.cnblogs.com/missdx/p/12343771.html  
如何合并多个分支：  
https://www.it1352.com/798309.html  
- 创建分支：  
`git branch <branch name>`  
- 查看各个分支所指向的对象  
`git log --oneline --decorate`  
- 切换分支  
`git checkout <branch name>`  
- 输出你的提交历史、各个分支的指向以及项目的分支分叉情况。  
`git log --oneline --decorate --graph --all`  
- 查看所有的现有分支  
`git branch -a`  
- 查看更改  
`git status`  
- 查看当前分支  
`git branch`  
- 切换分支  
`git switch <branch name>`  
- 切换分支，如果分支不存在，先创建一个分支，然后再切换  
`git switch -c <branch name>`或者`git checkout -b`  
- 查看本地所有分支  
`git branch`  
- 查看远程所有分支  
`git branch -r`  
- 查看本地和远程所有分支  
`git branch -a`  
- 删除分支  
`git branch -d <branchname>`  
- 删除远程分支  
`git branch -d -r <branchname>`# 使用-D则表示强制删除，相当于 --delete --force  
- 重命名分支   
`git branch (-m | -M) <oldbranch> <newbranch>`# -M表示强制重命名  
## ...or create a new repository on the command line

`echo "# -" >> README.md`

`git init  # to transfer the current file to repository`

`git add .  # to add all the changes `

`git commit -m "first commit"  # to commit the all files to local repository`

`git branch -M main` # 将当前的分支重命名为main

`git remote add origin https://github.com/wangxl12/DataStructure_Algorithms.git` # 将远程仓库添加进来，并起别名为origin

`git push -u origin main`  # 将会关联到远程的main 分支上，以后就可以git push不指定参数了（使用了-u），以后就默认关联到远程仓库的main分支上，远程仓库的其他分支可以有，只是作为备份使用的.


## ...or push an existing repository from the command line 

`git remote add origin https://github.com/wangxl12/DataStructure_Algorithm.git`

`git branch -M main`

`git push -u origin main`
