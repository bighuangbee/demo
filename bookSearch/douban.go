/**
 * @desc //TODO $
 * @param $
 * @return $
 **/
package main

import (
	"demo/common/worker"
	"encoding/json"
	"fmt"
	"gopackage/network/request"
	"net/url"
	"strings"
	"time"
	"unicode/utf8"
)

var bookUrl = "https://book.douban.com/j/subject_suggest"

//var text = "“作为一个想换工作结束异地的已婚未育育龄女性，我很担心这个政策对我换工作的影响。”在上海某事业单位工作的孙女士告诉澎湃新闻记者。\n\n她所说的政策，就是近期多地密集出台的延长生育假的政策，有的省市将生育假从30天延长到了60天，也有的省份延长产假60天甚至90天。\n\n不过，在上海国企工作现育有一孩的章女士则对澎湃新闻记者表示，听到这样的消息并未有任何担忧，“女同胞们生存在企业环境中没有必要极力与二胎三胎撇清关系，我们的自信来源于我们的工作经验和能力，女性为什么要通过少生孩子去向社会证明自己可以被信任呢。”\n\n从各地生育鼓励政策来看，总体是三种方式，延长产假、生育假、夫妻双方享受育儿假等，发放生育津贴或补贴金，参保女职工生育三孩的费用纳入生育保险待遇支付范围。\n\n\n部分地区延长生育相关假期情况 制图 彭艳秋武汉科技大学金融证券研究所所长董登新向澎湃新闻表示，生育政策是一个系统工程，从怀孕到学龄前的教育，整个过程当中都应该有政府的支持，这需要大量的财政投入。他指出，鼓励生育或提高综合生育率，最重要还是在孩子学前教育前整个阶段的配套服务。政策要跟上，从怀孕到生产到产后的休假哺乳期，尤其是小孩的入托和入幼的问题，要有完善的、配套的、无缝衔接的政策。如果不能构建这样一张网的话，这个效果可能会大打折扣。延长产假、生育假对女性就业有何影响\n\n延长产假、生育假等会给女性就业带来影响吗？\n\n复旦大学人口研究所教授任远对澎湃新闻记者表示，近期出台的政策，对于减少家庭生育的压力，对加强生育的服务和支持都是非常积极有益的。但是，生育假的延长可能也会有一些负面的作用，例如生育假的延长会增加企业的成本，也会弱化女性在就业市场上的竞争力。\n\n“生育保险能够有效地减少企业因为女性职工生育的成本。但是企业的考虑可能不仅仅是生育津贴的工薪成本，女性生育和哺乳期带来的劳务中断，也构成了企业发展的成本，企业对于各种生育相关的假期是缺乏热情的。”任远还提醒，生育假本来是保护家庭和女性的政策，要避免在实施中却伤害女性发展。\n\n上海财经大学经济学院副教授王学博告诉澎湃新闻记者，延长产假的政策初衷是好的，女性生育孩子为社会和国家做出了贡献，应该让她们得到更好的休息。但如果让企业承担生育率提高的全部成本，长期可能会造成意想不到的后果。\n\n“从根本上来说，企业的目标是追求利润，在优胜劣汰的市场竞争机制下，企业面临巨大的生存压力，他们没有激励和动力去承担这些成本”，王学博表示，很多研究发现，劳动力市场上企业对女性劳动力存在歧视，很多企业在招聘时更愿意选择男性劳动力。如果女性在劳动力市场本身就处在弱势地位，延长产假政策会让她们在劳动力市场上的处境恶化。\n\n王学博认为，女性生育孩子是家庭行为，家庭和国家是直接的受益方，个人和国家都负担一些是合理的，让企业尽量负担得更少一些。\n\n暨南大学经济学院、经济与社会研究院院长冯帅章则对澎湃新闻表示，无需过度担忧，这个政策总体而言是很好的政策。“女性处境两难，现在老龄化严重、生育率低，需要提高生育率，另一方面，人口马上进入拐点，面临着劳动人口不足，女性都退出劳动力市场恐怕也不行。那我们的政策肯定要创造条件，让女性不必只能二选其一。未来的政策目标，就是要创造这样的环境，生育假便是其中的一部分。”\n\n“如果是以法律的形式将其确定下来，那么对于每个企业都将一样，这样对于女性就业的负面影响会降低，因为大家都形成了这样的习惯和预期，成为理所当然。”冯帅章认为，目前政策的假期时长还是较为适当的。\n\n同时，冯帅章认为，这样的政策对不同的对象影响程度会不同。对受教育程度偏低的群体，就业冲击相对较大，因此还需要提高人力资本，通过接受更高的教育，拥有更高的技能，降低冲击，这对于男性是同样的。人力资本，是不可忽视的因素。\n\n如何减少生育假的不利影响？\n\n任远建议，作为生育配套政策的各种生育假、育儿假、配偶的陪产假等，主要的问题还不是要不要有这些假期，而是要考虑这些政策如何来实施，从而可以对企业的损害最小，对女性的不利影响最小。例如，可以鼓励一些有条件的岗位实施弹性的就业制度，可以允许婴幼儿母亲有一段时间的在线工作时间，这样也能保证女性的劳动力市场参与，也有助于企业维持正常业务运行，对企业的影响也会最小。\n\n任远表示，由于各种生育关联的配套政策牵涉到不同主体的利益和需求，因此政策的制定实施需要多听取公众的意见，会有利于将好事办好，出台多方共赢的政策。\n\n冯帅章建议，可以在现阶段政策的基础上，考虑增加男性的生育相关假期，一方面对女性的歧视会减少，另一方面，男性承担更多的家庭责任和享受更多的亲子互动，对于幼儿成长和家庭和谐都有好处，“女性既需要工作又需要照顾家庭，压力很大，如果男性能够参与进来，对家庭对社会都有益处。”\n\n假期增多会影响经济增长吗？\n\n冯帅章认为要动态地看这个问题，还是要从人力资本的角度着手，“这就涉及到国家现在提的高质量发展，转变增长方式。以人力资本驱动，以提高效率驱动，而不是以时间驱动，家庭幸福，工作效率会更高。”\n\n“我们的工作需要幸福的家庭作后盾，也需要企业的支持和尊重。但如果只有一家企业这样做，压力会比较大，因此需要政府来做这样的引导。现在政府出台这样的政策，正是起到这样的作用。”冯帅章说道。"
var text = "作为一个想换工作结束异地的已婚未育育龄女性我很担心这个政策对我换工作的影响"

var filterText = []string{"“", "，", "。", "\n"}


type DoubanSubject struct {
	Title string `json:"title"`
	Url string `json:"url"`
	Pic string `json:"pic"`
	Author string `json:"author"`
	Year string `json:"year"`
	Type string `json:"type"`
	Id string `json:"id"`
}

type SubjectResult struct {
	key string
	Subject []DoubanSubject
}

func ignoreWord(key string)bool{
	for _, f := range filterText {
		if strings.Contains(key, f){
			return true
		}
	}
	return false
}

func main() {
	t1 := time.Now()

	str := []rune(text)
	L := utf8.RuneCountInString(text)

	w := worker.New(10)

	go func() {
		for i := 0; i < L; i++ {
			key := string(str[i])
			if ignoreWord(key){
				continue
			}

			w.Add(func() interface{} {
				resp, err := BookSearch(key)
				if err != nil{
					fmt.Println("err:", err)
				}
				return SubjectResult{
					key:     key,
					Subject: resp,
				}
			})
		}
		close(w.Tasks)
	}()

	cb := func(result interface{})interface{} {
		sub, ok := result.(SubjectResult)
		if ok{
			fmt.Println("----=====",sub)
		}

		return 1
	}
	w.Run(cb)
	w.Wg.Wait()

	fmt.Println("time duration:", time.Now().Sub(t1))
}

func a()  {
	str := []rune(text)
	L := utf8.RuneCountInString(text)
	for i := 0 ; i < L; i++{
		key := string(str[i])

		if ignoreWord(key){
			continue
		}

		t1 := time.Now()
		result, err := BookSearch(key)
		fmt.Println("key:", key, err, time.Now().Sub(t1), result)
	}
}

func BookSearch(key string) (data []DoubanSubject, err error) {
	h := request.RequestHeaders{}
	h["User-Agent"] = "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/96.0.4664.55 Safari/537.36"

	p := request.RequestParams{}
	p["q"] = key

	var resp []byte
	resp, err =  request.Request("GET", bookUrl, p, h)
	if err != nil{
		return nil, err
	}

	var respStr string
	respStr, err = url.QueryUnescape(string(resp))
	if err != nil{
		return nil, err
	}

	json.Unmarshal([]byte(respStr), &data)
	return
}
