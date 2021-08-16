const format_date = date => {
  const months = ['Jan.', 'Feb.', 'Mar.', 'Apr.', 'May.', 'Jun.', 'Jul.', 'Aug.', 'Sep.', 'Oct.', 'Nov.', 'Dec.']
  date = date.split('T')[0].split('-')

  return `${date[2]} ${months[date[1] - 1]} ${date[0]}`
}

const set_cookie = (key, val, expires = 1209600) => { // 2 weeks is the default expire time
  document.cookie = `${key}=${val};Max-Age=${expires};path=/;samesite=strict`
}

const check_cookie = key => {
  return document.cookie.split(';').some(item => item.trim().startsWith(`${key}=`))
}

const ask_donation = () => {
  alert('Hello.\nIf you find this project useful and want me to update it regularly, consider donating a small amount to help me cover the costs of development.\n\nYour donations are appreciated!')
}

const check_donation = () => {
  if (!check_cookie('donation')) {
    set_cookie('donation', 1)
    ask_donation()
  }
}

document.addEventListener('DOMContentLoaded', () => {
  const desc = document.querySelector('#description > p')
  const download = document.getElementById('download_btn')

  fetch('https://api.github.com/repos/blaumaus/le_chiffre/releases?per_page=1')
    .then(res => res.json())
    .then(res => {
      const version = res[0]?.tag_name || 'Unknown'
      const date = res[0]?.published_at || 'Unknown'
      const download_url = res[0].assets[0]?.browser_download_url || 'https://github.com/Blaumaus/le_chiffre/releases'
      
      desc.textContent = `The latest cheat version is ${version}, it has been updated on ${format_date(date)}`
      download.textContent = 'Direct download'
      download.href = download_url
    })
    .catch(e => console.log(e))

  // setTimeout(check_donation, 5000)

  insights.init('QZXDaLRWC1XvtWGM', { ignoreErrors: true })
  insights.trackPages({
    search: true
  })

  analytics.init('ZAX-2szETYGP')
  analytics.trackViews()
})