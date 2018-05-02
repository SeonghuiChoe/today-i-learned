# Zsh completions
[Completions 설정](https://github.com/zsh-users/zsh-completions)

## OS X

Zsh을 사용할 때 자동완성을 설정하여 좀 더 생산성 있는 작업이 가능합니다. 그러나 하라는 설정을 그대로 따라해도 안되는 경우에 아래 부분을 확인해주세요.

```bash
# zsh-completions OS X
# To activate these completions, add the following to your .zshrc:
#   fpath=(/usr/local/share/zsh-completions $fpath)
# You may also need to force rebuild `zcompdump`:
#   rm -f ~/.zcompdump; compinit
# Additionally, if you receive "zsh compinit: insecure directories" warnings when attempting to load these completions, you may need to run this:
#   chmod go-w /usr/local/share
```
