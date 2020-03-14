# Docker

!> Work in process!

Todo: basic concepts like what is

- Tag
- DockerFile
- Container
- Image

Learn Docker & Containers using Interactive Browser-Based Scenarios
From <https://www.katacoda.com/courses/docker>

Docker - Docker Playground
From <https://www.katacoda.com/courses/docker/playground>


Docker Cheat Sheet for Sysadmins
From <https://www.linuxsysadmins.com/docker-cheat-sheet-for-sysadmins/?fbclid=IwAR1cNLMuAqlxcgZrvWHIT0m_48Fcqxt0RtFpUR9AglTeQxPo2tJranRlbgs> 

Docker Cheat Sheet for Sysadmins
From <https://www.linuxsysadmins.com/docker-cheat-sheet-for-sysadmins/?fbclid=IwAR1cNLMuAqlxcgZrvWHIT0m_48Fcqxt0RtFpUR9AglTeQxPo2tJranRlbgs>

Run containers through a simple, yet powerful graphical user interface.
From <https://kitematic.com/> 

docker-compose with php/mysql/phpmyadmin/apache
From <https://gist.github.com/jcavat/2ed51c6371b9b488d6a940ba1049189b>


https://github.com/docker/labs/blob/master/beginner/chapters/webapps.md

http://phase2.github.io/devtools/common-tasks/ssh-into-a-container/

https://www.youtube.com/watch?v=K6WER0oI-qs



---
For example if we run php app and we made a change to src files and refresh the page nothink will happened.
Docker countainer wont reflect new version of the file and this is because when we build the image it made a copy of the src file to see the change you will need to rebuild the image and spin up a new container from the updated image.
During development this is obviousle a massive pain and this is where volumes come in. there are two types

	1. Share folder between the host and the container 
	Docker run -p localdir:dockerdir 80:80 -v hello-php
---


----
In compose-file
Build: . Is when you want to build the container from a dockerfile

Eather you can specify instead of build, image: and image name:tag 
---

-----
1. stop all containers: docker kill $(docker ps -q)
2. remove all containers. docker rm $(docker ps -a -q)
3. remove all docker images. docker rmi $(docker images -q)

From <https://www.google.com/search?q=remove+all+docker+containers&pws=0&gl=us&gws_rd=cr> 

---
