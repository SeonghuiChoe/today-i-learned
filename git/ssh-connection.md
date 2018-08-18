# Testing your SSH connection
PM2를 사용하고있는 중에 deploy를위한 ecosystem.config.js안에 Github정보를 적었지만 권한이 없어서 문제가 발생했다.

## SSH key
ssh-keygen을 생성한다. 기본으로 'id_dsa'라는 이름으로 생성되는데 다른이름으로 생성한뒤 비밀키를 서버에 등록하고 공개키를 github에 등록한다.

## Testing
[ssh -T git@github.com](https://help.github.com/articles/testing-your-ssh-connection/)
